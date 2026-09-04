class Solution {
private:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void solve(vector<vector<char>>& grid,int r,int c){
        if( grid[r][c]!='1' ){
            return;
        }
        grid[r][c] = 0;
        
        for(auto [dr,dc] : dir) {
            int nr = r+dr;
            int nc = c+dc;
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == '1') {
                solve(grid,nr,nc);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
