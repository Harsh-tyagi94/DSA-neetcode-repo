class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i=0;i<n;i++) {
            nums[i] ^= i+1;
            res ^= nums[i];
        }

        return res;
    }
};
