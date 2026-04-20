class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int n:nums) {
            uset.insert(n);
        }

        int res = 0;
        while(!uset.empty()) {
            int t = *uset.begin();
            uset.erase(t);
            int len = 0;
            while(uset.count(t-1-len)) {
                uset.erase(t-1-len);
                len += 1;
            }
            while(uset.count(t+1)) {
                uset.erase(t+1);
                t += 1;
                len += 1;
            }
            res = max(res, 1 + len);
        }
        return res;
    }
};

/*
nums = [0,3,2,5,4,6,1,1]

*/