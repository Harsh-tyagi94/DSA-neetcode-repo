class Solution {
private:
    int helper(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if(idx == 0){
            return (amount % coins[0] == 0);
        }
        if (dp[amount][idx] != -1) {
            return dp[amount][idx];
        }
        int take = 0;
        if (amount >= coins[idx]) {
            take=helper(coins, amount - coins[idx], idx, dp);
        }
        int not_take=helper(coins,amount,idx-1,dp);
        return dp[amount][idx]=take+not_take;
}

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n, -1));
        return helper(coins, amount,n-1, dp);
    }
};

// class Solution {
// private:
//     void helper(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp, int n) {
//         if (amount == 0) {
//             dp[amount][idx] = 1;
//             return;
//         }
//         if (dp[amount][idx] != -1) {
//             return;
//         }
//         dp[amount][idx] = 0;
//         for (int i = idx; i < n; ++i) {
//             if (amount >= coins[i]) {
//                 helper(coins, amount - coins[i], i, dp, n);
//                 dp[amount][idx] += dp[amount - coins[i]][i];
//                 if (dp[amount][idx] > INT_MAX) {  // Check for integer overflow
//                     dp[amount][idx] = INT_MAX;
//                 }
//             }
//         }
//     }

// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(amount + 1, vector<int>(n, -1));
//         helper(coins, amount, 0, dp, n);
//         return dp[amount][0];
//     }
// };