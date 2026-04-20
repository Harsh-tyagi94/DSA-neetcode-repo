class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int res = nums[0];
        for(int n:nums) {
            maxSum = n + max(0, maxSum);
            res = max(res, maxSum);
        }

        return res;
    }
};