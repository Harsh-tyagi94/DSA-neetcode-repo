class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int idx=0,n=cost.size();
        if(n==0){
            return cost[n];
        }
        vector<int> dp(n+1);
        dp[0]=cost[n-1];
        dp[1]=cost[n-2];
        for(idx=2;idx<n;idx++){
            dp[idx]=cost[n-1-idx]+min(dp[idx-1],dp[idx-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};