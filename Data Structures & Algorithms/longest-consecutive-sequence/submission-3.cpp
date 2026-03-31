class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> v(nums.begin(),nums.end());
        int res = 0;
        for(int num:nums) {
            if(!v.count(num-1)) {
                int len = 1;
                while(v.count(num+len)) len++;
                res = max(res,len);
            }
        }
        return res;
    }
};
