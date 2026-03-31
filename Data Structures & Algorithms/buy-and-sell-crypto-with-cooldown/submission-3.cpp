class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for(int index=n-1;index>=0;index--) {
            for(int buy=0;buy<2;buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(dp[index+1][1], -prices[index] + dp[index+1][0]);
                } else {
                    profit = max(dp[index+1][0], prices[index] + dp[index+2][1]);
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};