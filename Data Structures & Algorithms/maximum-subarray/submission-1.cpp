class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int max_sum = nums[0];

        for(int i=1;i<nums.size();i++) {
            max_sum = max(nums[i],max_sum+nums[i]);
            res = max(res,max_sum);
        }
        return res;
    }
};
