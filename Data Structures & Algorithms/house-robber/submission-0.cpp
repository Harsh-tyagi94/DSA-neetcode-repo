class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),idx=0;
        vector<int> dp(n+1);
        if(n==1){
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=nums[1];
        if(n>2){
            dp[2]=nums[2]+nums[0];
            for(idx=3;idx<n;idx++){
                dp[idx]=nums[idx]+max(dp[idx-2],dp[idx-3]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};
