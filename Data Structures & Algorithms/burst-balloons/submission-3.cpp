class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int l,int h) {
        if(l>h) return 0;
        if(dp[l][h]) return dp[l][h];
        for(int i=l;i<=h;i++) {
            int left = helper(nums,l,i-1);
            int right = helper(nums,i+1,h);
            dp[l][h] = max(dp[l][h],left+right+nums[l-1]*nums[i]*nums[h+1]);
        }
        return dp[l][h];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp.resize(n+2,vector<int>(n+2,0));
        return helper(nums,1,n);
    }
};
