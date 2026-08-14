class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> updated_nums;
        updated_nums.push_back(1);
        updated_nums.insert(updated_nums.end(), nums.begin(), nums.end());
        updated_nums.push_back(1);
        
        dp.resize(n+2, vector<int>(n+2, 0));
        for(int l=n;l>0;l--) {
            for(int r=l;r<=n;r++) {
                for(int k=l;k<=r;k++) {
                    dp[l][r] = max(
                        dp[l][r], dp[l][k-1] + dp[k+1][r] + updated_nums[l-                       1]*updated_nums[k]*updated_nums[r+1]
                    );
                }
            }
        }
        return dp[1][n];
    }
};