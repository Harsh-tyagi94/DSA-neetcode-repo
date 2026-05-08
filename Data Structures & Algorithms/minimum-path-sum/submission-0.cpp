class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n+1, 0);
        for(int i=0;i<n;i++) dp[i+1] = grid[0][i] + dp[i];

        for(int i=1;i<m;i++) {
            vector<int> old_dp = dp;
            dp[1] += grid[i][0];
            for(int j=1;j<n;j++) {
                dp[j+1] = grid[i][j] + min(dp[j], old_dp[j+1]);
            }
        }

        return dp[n];
    }
};