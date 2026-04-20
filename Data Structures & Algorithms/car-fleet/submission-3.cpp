class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        int n = position.size();
        for(int i=0;i<n;i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end());
        double prev_time = double(target - vec[n-1].first)/vec[n-1].second;
        int fleet = 1;
        for(int i=n-2;i>=0;i--) {
            double curr_time = double(target - vec[i].first)/vec[i].second;
            if(curr_time > prev_time) {
                fleet += 1;
                prev_time = curr_time;
            }
        }
        return fleet;
    }
};

/*
prev_time = 1


*/