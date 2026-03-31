class Solution {
private:
    int helper(vector<int>& coins,int amount,vector<int>& dp){
        if(amount==0){
            dp[amount]=0;
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
                int value=helper(coins,amount-coins[i],dp);
                if(ans>value && value!=INT_MAX){
                    ans=value+1;
                }
            }
        }
        dp[amount]=ans;
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        vector<int> dp(amount+1,-1);
        int sol=helper(coins,amount,dp);
        return (sol==INT_MAX) ? -1 : sol;
    }
};