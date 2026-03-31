class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,max_count=INT_MIN,n=prices.size();
        if(n<=1){
            return profit;
        }
        for(int i=n-2;i>=0;i--){
            max_count=max(max_count,prices[i+1]);
            profit=max(profit,-prices[i]+max_count);
        }
        return max(profit,0);
    }
};