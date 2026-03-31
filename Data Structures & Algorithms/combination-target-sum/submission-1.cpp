class Solution {
    void backtrack(vector<int>& nums,int target,vector<int> ans,int index) {
        if(target < 0 || index >= nums.size()) return;
        if(target == 0) {
            res.push_back(ans);
            return;
        }

        if(target > 0) backtrack(nums,target,ans,index+1);
        if(target - nums[index] >= 0) {
            ans.push_back(nums[index]);
            backtrack(nums,target-nums[index],ans,index);
        }
        return;
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums,target,{},0);
        return res;
    }
};
