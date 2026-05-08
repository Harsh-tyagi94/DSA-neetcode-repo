class Solution {
    vector<vector<int>> dp;
    int sum = 0;
public:
    int helper(vector<int>& nums, int n,int index, int target, int window_sum) {
        if(index >= n) return target == window_sum;

        if(dp[index][window_sum+sum] != -1) return dp[index][window_sum+sum]; 
        // add case
        int add = helper(nums, n, index+1, target, window_sum + nums[index]);

        // subtract case
        int subtract = helper(nums, n, index+1, target, window_sum - nums[index]);

        return dp[index][window_sum+sum] = add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        for(int n:nums) sum += n;
        dp.resize(nums.size(), vector<int>(2*sum+1, -1));
        return helper(nums, nums.size(), 0, target, 0);
    }
};