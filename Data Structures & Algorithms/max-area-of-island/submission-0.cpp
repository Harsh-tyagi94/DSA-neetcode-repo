class Solution {
private:
    int solve(vector<vector<int>>& grid,int r,int c){
        if(grid[r][c]!=1){
            return 0;
        }
        if(grid[r][c]==1){
            grid[r][c]=0;
        }
        int left = c>0 ? solve(grid,r,c-1) : 0;
        int right = c<grid[0].size()-1 ? solve(grid,r,c+1) : 0;
        int up = r>0 ? solve(grid,r-1,c) : 0;
        int down = r<grid.size()-1 ? solve(grid,r+1,c) : 0;
        return 1+(left+right+up+down);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;
    }
};