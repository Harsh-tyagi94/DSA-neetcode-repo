class Solution {
    void backtrack(vector<int>& nums,int target,vector<int>& ans,int index) {
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        if(target < 0 || index >= nums.size()) return;
        
        if(target - nums[index] >= 0) {
            ans.push_back(nums[index]);
            backtrack(nums,target-nums[index],ans,index+1);
            ans.pop_back();
        }
        while(index+1 < nums.size() && nums[index] == nums[index+1]) index++;
        if(target > 0) backtrack(nums,target,ans,index+1);
        
        return;
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,ans,0);
        return res;
    }
};

