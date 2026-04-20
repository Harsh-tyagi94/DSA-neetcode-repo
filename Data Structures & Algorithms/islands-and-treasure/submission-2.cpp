class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    void change_lands_dist(vector<vector<int>>& grid,int r,int c,int m,int n) {
        if(grid[r][c] == -1) {
            return;
        }

        for(auto [dr,dc] : dir) {
            int nr = r+dr;
            int nc = c+dc;

            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>grid[r][c]) {
                grid[nr][nc] = 1+grid[r][c];
                change_lands_dist(grid,nr,nc,m,n);
            }
        }
        return; 
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    change_lands_dist(grid,i,j,m,n);
                }
            }
        }
    }
};
