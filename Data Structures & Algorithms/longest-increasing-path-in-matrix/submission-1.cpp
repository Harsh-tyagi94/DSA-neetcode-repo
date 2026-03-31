class Solution {
private:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int up = (i > 0 && matrix[i][j] < matrix[i-1][j]) ? helper(matrix, dp, i-1, j, m, n) : 0;
        int down = (i < m - 1 && matrix[i][j] < matrix[i+1][j]) ? helper(matrix, dp, i+1, j, m, n) : 0;
        int left = (j > 0 && matrix[i][j] < matrix[i][j-1]) ? helper(matrix, dp, i, j-1, m, n) : 0;
        int right = (j < n - 1 && matrix[i][j] < matrix[i][j+1]) ? helper(matrix, dp, i, j+1, m, n) : 0;
        
        dp[i][j] = 1 + max({up, down, left, right});
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, helper(matrix, dp, i, j, m, n));
            }
        }
        
        return ans;
    }
};