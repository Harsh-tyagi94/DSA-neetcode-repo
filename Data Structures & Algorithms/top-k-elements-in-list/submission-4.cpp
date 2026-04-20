class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int n:nums) {
            ump[n] += 1;
        }
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qmin;
        for(auto it=ump.begin();it!=ump.end();it++) {
            if(qmin.size() == k) {
                pair<int,int> r = qmin.top();
                qmin.pop();
                if(it->second > r.first) {
                    r = {it->second, it->first};
                }
                qmin.push(r);
                continue;
            }
            qmin.push({it->second, it->first});
        }
        vector<int> res;
        while(!qmin.empty()) {
            res.push_back(qmin.top().second);
            qmin.pop();
        }
        return res;
    }
};
