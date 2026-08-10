class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        int res = 0;
        for(int r=0;r<row;r++) {
            for(int c=0;c<col;c++) {
                if(grid[r][c] == 1) {
                    for(auto [dr, dc]:dir) {
                        int nr = r + dr, nc = c + dc;
                        if(nr < 0 || nc < 0 ||nr>=row || nc>=col || grid[nr][nc] == 0) 
                            res += 1;
                    }
                }
            }
        }
        return res;
    }
};