class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int n = position.size();
        for(int i=0;i<n;i++) {
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());

        int carfleet_cnt = 0;
        double time_taken = 0;
        for(int t=n-1;t>=0;t--) {
            double Time = double(target - vec[t].first)/vec[t].second;
            if(Time > time_taken) {
                carfleet_cnt++;
                time_taken = Time;
            }
        }
        return carfleet_cnt;
    }
};