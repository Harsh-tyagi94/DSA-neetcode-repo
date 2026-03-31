class Solution {
private:
    void solve(vector<vector<char>>& grid,int r,int c){
        if(r<0 || r>grid.size() || c<0 || c>grid[0].size() || grid[r][c]!='1' ){
            return;
        }
        if(grid[r][c]=='1'){
            grid[r][c]='2';
        }
        //up call
        if(r>0)
        solve(grid,r-1,c);
        //down call
        if(r<grid.size()-1)
        solve(grid,r+1,c);
        //left call
        if(c>0)
        solve(grid,r,c-1);
        //right call
        if(c<grid[0].size()-1)
        solve(grid,r,c+1);
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
