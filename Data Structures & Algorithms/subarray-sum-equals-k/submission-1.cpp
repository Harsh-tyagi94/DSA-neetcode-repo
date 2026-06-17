class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int res = 0, sum = 0;
        ump[0] += 1;
        for(int n:nums) {
            sum += n;
            if(ump.count(sum-k)) res += ump[sum-k];
            ump[sum] += 1;
        }
        return res;
    }
};