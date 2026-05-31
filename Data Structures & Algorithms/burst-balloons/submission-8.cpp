class Solution {
public:
    vector<vector<int>> dp;
    int find_maxCoins(vector<int>& nums, int l, int r) {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for(int k=l;k<=r;k++) {
            int left = find_maxCoins(nums, l, k-1);
            int right = find_maxCoins(nums, k+1, r);
            dp[l][r] = max(dp[l][r], nums[l-1]*nums[k]*nums[r+1] + left + right);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int> updated_nums;
        updated_nums.push_back(1);
        updated_nums.insert(updated_nums.end(), nums.begin(), nums.end());
        updated_nums.push_back(1);
        
        dp.resize(nums.size()+2, vector<int>(nums.size()+2, -1));
        return find_maxCoins(updated_nums, 1, nums.size());
    }
};