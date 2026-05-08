class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dollor=0, ten_dollor=0;
        for(int bill:bills) {
            if(bill == 10) {
                if(!five_dollor) return false;
                five_dollor -= 1;
                ten_dollor += 1;
            } else if(bill == 20) {
                int cost = 0;
                if(ten_dollor) {
                    cost += 10;
                    ten_dollor -= 1;
                }

                while(cost < 15) {
                    if(!five_dollor) return false;
                    five_dollor -= 1;
                    cost += 5;
                }
            } else {
                five_dollor += 1;
            }
        }
        return true;
    }
};