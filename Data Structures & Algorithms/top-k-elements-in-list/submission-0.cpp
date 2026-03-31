class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++) {
            ump[nums[i]]++;
        }

        set<pair<int,int>> ost;
        for(auto it=ump.begin();it!=ump.end();it++) {
            ost.insert({it->second,it->first});
            if(ost.size() > k) {
                auto c = *ost.begin();
                ost.erase(c);
            }
        }

        vector<int> res;
        for(auto it=ost.begin();it!=ost.end();it++) {
            res.push_back(it->second);

        }
        return res;
    }
};
