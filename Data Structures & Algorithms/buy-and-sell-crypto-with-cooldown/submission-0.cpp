class Solution {
private:
    int solve(vector<int>& prices,int buying,int idx,vector<vector<int>>& dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][buying]!=-1){
            return dp[idx][buying];
        }
        int profit=0;
        if(buying){
            int cooldown=0+solve(prices,buying,idx+1,dp); 
            int buy=-prices[idx]+solve(prices,0,idx+1,dp);
            profit=max(buy,cooldown);
        }
        else{
            int cooldown=0+solve(prices,buying,idx+1,dp);
            int sell=solve(prices,1,idx+2,dp)+prices[idx];
            profit=max(cooldown,sell);
        }
        return dp[idx][buying]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,1,0,dp);
        
    }
};

