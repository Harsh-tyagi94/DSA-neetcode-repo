class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> row_cnt(ROWS, 0), col_cnt(COLS, 0);

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    row_cnt[r]++;
                    col_cnt[c]++;
                }
            }
        }

        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1 && max(row_cnt[r], col_cnt[c]) > 1) {
                    res++;
                }
            }
        }

        return res;
    }
};