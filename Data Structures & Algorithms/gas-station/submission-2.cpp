class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gas_total = 0, cost_total = 0;
        for(int i=0;i<n;i++) {
            gas_total += gas[i];
            cost_total += cost[i];
            gas[i] -= cost[i];
        }
        if(gas_total < cost_total) return -1;

        int total = 0;
        int index = 0;
        for(int i=0;i<n;i++) {
            if(total + gas[i] < 0) {
                total = 0;
                index = i+1;
            } else {
                total += gas[i];
            }
        }
        return total >= 0 ? index : -1;
    }
};