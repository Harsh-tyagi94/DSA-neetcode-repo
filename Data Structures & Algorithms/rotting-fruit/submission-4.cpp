class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int fresh_oranges = 0;
        queue<pair<int,int>> rotten_oranges;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) fresh_oranges += 1;
                else if(grid[i][j] == 2) rotten_oranges.push({i,j});
            }
        }

        if(rotten_oranges.empty()) return fresh_oranges == 0 ? 0 : -1;

        int mintime = 0;
        int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        while(!rotten_oranges.empty() && fresh_oranges) {
            int len = rotten_oranges.size();
            for(int i=0;i<len;i++) {
                int r = rotten_oranges.front().first;
                int c = rotten_oranges.front().second;
                rotten_oranges.pop();
                for(auto [dr,dc]:dir) {
                    int nr = r+dr;
                    int nc = c+dc;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1) {
                        fresh_oranges -= 1;
                        grid[nr][nc] = 2;
                        rotten_oranges.push({nr,nc});
                    }
                }
            }

            mintime += 1;
        }

        if(fresh_oranges) return -1;

        return mintime;
    }
};