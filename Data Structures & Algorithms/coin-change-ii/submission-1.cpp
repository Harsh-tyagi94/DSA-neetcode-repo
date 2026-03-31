class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint> dp(amount+1, 0);

        dp[0] = 1;
        for(int i=0;i<n;i++) {
            for(int target=coins[i];target<=amount;target++) {
                if(dp[target - coins[i]] == 0) continue;
                dp[target] = (dp[target] + dp[target-coins[i]]);
            }
        }
        return dp[amount];
    }
};

/*
coins = [2]
        ^

target = 3
dp[0] = 0
dp[2] = 1
dp[3] = -1

*/