class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_val = 0;
        for(auto interval:intervals) {
            max_val = max(max_val,interval[0]);
        }

        vector<int> StartEndOverLapping(max_val+1,0);

        for(auto interval:intervals) {
            StartEndOverLapping[interval[0]] = max(StartEndOverLapping[interval[0]],interval[1]);
        }

        vector<vector<int>> res;
        // exception case handling -- [0,0]
        for(auto interval:intervals) {
            if(interval[0] == 0 && interval[1] == 0) {
                res.push_back(interval);
                break;
            }
        }

        for(int i=0;i<StartEndOverLapping.size();i++) {
            if(StartEndOverLapping[i]) {
                if(res.size() == 0) res.push_back({i,StartEndOverLapping[i]});
                else if(res.back()[1] < i) {
                    res.push_back({i,StartEndOverLapping[i]});
                } else if(res.back()[1] >= i) {
                    int start = res.back()[0];
                    StartEndOverLapping[i] = max(StartEndOverLapping[i],res.back()[1]);
                    res.pop_back();
                    res.push_back({start,StartEndOverLapping[i]});
                }
            }
        }
        return res;
    }
};