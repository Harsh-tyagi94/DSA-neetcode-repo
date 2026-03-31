class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int fresh=0;

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int cnt = 0;
        while(fresh > 0 && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto [r,c] = q.front();
                q.pop();

                for(auto [dr,dc]:dir) {
                    int nr = r+dr;
                    int nc = c+dc;

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
            cnt++;
        }
        return fresh == 0 ? cnt : -1;
    }
};
