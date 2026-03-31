class Solution {
private:
    int ans = 0;
    
    int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        dp[l][r] = 0;
        for (int i = l; i <= r; i++) {
            int left = solve(nums, l, i - 1, dp);
            int right = solve(nums, i + 1, r, dp);
            dp[l][r] = max(dp[l][r], left + right + nums[l - 1] * nums[i] * nums[r + 1]);
        }
        return dp[l][r];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        ans = solve(nums, 1, n, dp);
        return ans;
    }
};