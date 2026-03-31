class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for(int i=0;i<n;i++) {
            if(gas[i] < cost[i]) continue;
            int curr_fuel = gas[i]-cost[i];
            for(int j=1;j<n;j++) {
                curr_fuel += gas[(i+j)%n];
                curr_fuel -= cost[(i+j)%n];
                if(curr_fuel < 0) {
                    break;
                }
            }

            if(curr_fuel >= 0) return i;
        }
        return -1;
    }
};