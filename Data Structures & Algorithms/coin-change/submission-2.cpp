class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int i=0;i<n;i++) {
            for(int a=coins[i];a<=amount;a++) {
                if(dp[a-coins[i]] == amount+1) continue;
                dp[a] = min(dp[a],1+dp[a-coins[i]]);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};