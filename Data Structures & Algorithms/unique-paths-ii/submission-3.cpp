class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for(int i=0;i<n;i++) {
            if(dp[i] != -1 && !obstacleGrid[0][i]) dp[i+1] = 1;
            cout<<dp[i+1]<<"\t";
        }

        for(int i=1;i<m;i++) {
            vector<int> old_dp = dp;
            if(obstacleGrid[i][0]) dp[1] = -1;
            for(int j=1;j<n;j++) {
                dp[j+1] = (max(0, dp[j]) + max(0, old_dp[j+1]));
                if(obstacleGrid[i][j]) dp[j+1] = -1;
                cout<<dp[j+1]<<"\t";
            }
        }

        return max(0, dp[n]);
    }
};