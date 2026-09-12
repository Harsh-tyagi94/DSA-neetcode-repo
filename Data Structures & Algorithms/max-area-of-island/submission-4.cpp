class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int find_area(vector<vector<int>>& grid,int r,int c,int m,int n){
        if( grid[r][c]!= 1 ){
            return 0;
        }
        grid[r][c] = 0;

        int solve = 0;
        
        for(auto [dr,dc] : dir) {
            int nr = r+dr;
            int nc = c+dc;
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1) {
                solve += find_area(grid,nr,nc,m,n);
            }
        }
        return 1+solve;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    res = max(res,find_area(grid,i,j,m,n));
                }
            }
        }
        return res;
    }
};