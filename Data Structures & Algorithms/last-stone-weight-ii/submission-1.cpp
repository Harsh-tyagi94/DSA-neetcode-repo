class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i=0;i<n;i++) {
            for(int t=0;t<=target;t++) {
                dp[i+1][t] = dp[i][t];
                if(t >= stones[i]) {
                    dp[i+1][t] = max(dp[i+1][t], dp[i][t-stones[i]] + stones[i]);
                }
            }
        }
        return stoneSum - 2*dp[n][target];
    }
};