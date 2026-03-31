class Solution {
private:
    int solve(vector<int>& nums, int target,int idx,vector<vector<int>>& dp,int offset){
        if(idx==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int left=solve(nums,target+nums[idx],idx+1,dp,offset);
        int right=solve(nums,target-nums[idx],idx+1,dp,offset);
        
        return left+right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int offset=sum;
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));
        return solve(nums,target,0,dp,offset);
    }
};