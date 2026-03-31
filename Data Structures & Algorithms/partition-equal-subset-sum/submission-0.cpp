class Solution {
public:
    int target = 0;
    vector<vector<bool>> dp;
    bool helper(vector<int>& nums,int index,int sum,int n) {
        if(index >= n) {
            return sum == target ? true : false;
        }

        if(dp[index][sum]) return true;

        if(helper(nums,index+1,sum,n)) {
            return dp[index][sum] = true;
        }

        if(sum + nums[index] <= target && helper(nums,index+1,sum+nums[index],n)) {
            return dp[index][sum] = true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        for(auto num:nums) {
            target += num;
        }
        if(target%2) return false;
        target /= 2;
        dp.resize(n, vector<bool>(target+1,false));
        return helper(nums,0,0,n);
    }
};
