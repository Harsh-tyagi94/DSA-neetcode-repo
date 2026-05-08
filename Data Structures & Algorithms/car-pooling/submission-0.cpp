class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for(auto trip:trips) {
            mp[trip[1]] += trip[0];
            mp[trip[2]] -= trip[0];
        }

        int currCapacity = 0;
        for(auto it=mp.begin();it!=mp.end();it++) {
            currCapacity += it->second;
            if(currCapacity > capacity) return false;
        }
        return true;
    }
};