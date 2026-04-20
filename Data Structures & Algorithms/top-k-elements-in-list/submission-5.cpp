class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int n:nums) {
            ump[n] += 1;
        }
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(auto it=ump.begin();it!=ump.end();it++) {
            freq[it->second].push_back(it->first);
        }
        vector<int> res;
        for(int i=n;i>0;i--) {
            for(int f:freq[i]) {
                res.push_back(f);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
