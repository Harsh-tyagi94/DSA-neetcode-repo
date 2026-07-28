class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i=0;i<n;i++) {
            for(int target=coins[i];target<=amount;target++)  {
                if(dp[target - coins[i]] == amount+1) continue;
                dp[target] = min(dp[target], 1 + dp[target - coins[i]]);
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

/*
coins = [1,2,5]
           ^


dp[1] = 1
dp[2] = 2
dp[3] = 3
dp[4] = 4

*/