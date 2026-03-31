class Solution {
    bool dfs(vector<int>& nums,int index,int n,unordered_map<int, bool>& memo) {
        if(index >= n) return false;
        if(index == n-1) return true;

        if(memo[index]) return memo[index];

        bool isComplete = false;
        nums[index] = min(nums[index], n-index+1);
        for(int i=nums[index];i>0;i--) {
            if(isComplete) return memo[index] = true;
            isComplete = dfs(nums,index+i,n,memo);
        }

        return memo[index] = isComplete;
    }
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums,0,nums.size(),memo);
    }
};