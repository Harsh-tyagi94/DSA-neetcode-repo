class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 0);
        for(int i=0;i<n;i++) {
            dp[i+1] = 1;
        }

        for(int i=1;i<m;i++) {
            vector<int> old_dp = dp;
            dp[1] = 1;
            for(int j=1;j<n;j++) {
                dp[j+1] = dp[j] + old_dp[j+1];
            }
        }

        return dp[n];
    }
};