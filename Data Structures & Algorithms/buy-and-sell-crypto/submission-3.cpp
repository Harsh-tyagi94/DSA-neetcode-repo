class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy_price = prices[0];
        for(int i=1;i<prices.size();i++) {
            res = max(res, prices[i]-buy_price);
            buy_price = min(buy_price, prices[i]);
        }
        return res;
    }
};