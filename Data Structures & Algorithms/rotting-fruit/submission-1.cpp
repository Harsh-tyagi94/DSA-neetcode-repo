class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int freshorange=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshorange++;
                }
            }
        }
        if(freshorange==0){
            return 0;
        }
        int time=-1;
        while(!q.empty()){
            time=time+1;
            int size=q.size();
            while(size>0){
                int r=q.front().first;
                int c=q.front().second;
                size--;
                q.pop();
                //up
                if(r>0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                    freshorange--;
                }
                //down
                if(r<grid.size()-1 && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                    freshorange--;
                }
                //left
                if(c>0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                    freshorange--;
                }
                //down
                if(c<grid[0].size()-1 && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                    freshorange--;
                }
            }
        }
        return freshorange==0 ? time : -1;
    }
};