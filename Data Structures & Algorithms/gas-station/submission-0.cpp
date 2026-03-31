class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),total_cost=0,idx=0,curr_tank=0;
        for(int i=0;i<n;i++){
            total_cost+=(gas[i]-cost[i]);
            curr_tank+=(gas[i]-cost[i]);

            if(curr_tank<0){
                idx=i+1;
                curr_tank=0;
            }
        }
        
        return total_cost>=0 ? idx : -1;
    }
};