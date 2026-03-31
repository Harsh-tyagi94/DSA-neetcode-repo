class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool helper(vector<vector<char>>& board, string word, int r, int c, int k,
    vector<vector<bool>>& dp, int m, int n) {
        if(k == word.length()) return true;
        if(dp[r][c]) return false;

        dp[r][c] = true;
        for(auto [dr,dc]:dir) {
            int nr = r + dr, nc = c + dc;
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == word[k] && !dp[nr][nc]) {
                if(helper(board, word, nr, nc, k+1, dp, m, n)) return true;
            }
        }
        dp[r][c] = false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) return true;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(board[r][c] == word[0]) {
                    if(helper(board, word, r, c, 1, dp, m, n)) return true;
                }
            }
        }
        return false;
    }
};
