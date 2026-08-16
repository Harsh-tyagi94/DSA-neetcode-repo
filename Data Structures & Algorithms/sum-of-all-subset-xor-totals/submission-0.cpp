class Solution {
    int dfs(vector<int>& nums, int index, int t) {
        if(index >= nums.size()) return t;

        return dfs(nums, index+1, t^nums[index]) + dfs(nums, index+1, t);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};