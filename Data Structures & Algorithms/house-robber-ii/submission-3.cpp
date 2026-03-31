class Solution {
private:
    int helper(vector<int>& num){
        int n=num.size(),idx=0;
        vector<int> dp(n+1,0);
        dp[0]=num[0];
        if(n==1){
            return dp[0];
        }
        dp[1]=num[1];
        if(n>2){
            dp[2]=num[0]+num[2];
            for(idx=3;idx<n;idx++){
                dp[idx]=num[idx]+max(dp[idx-2],dp[idx-3]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),idx=0;
        if(n==1) return nums[0];
        vector<int> dp1(nums.begin(),nums.end()-1);
        vector<int> dp2(nums.begin()+1,nums.end());
        return max(helper(dp1),helper(dp2));
    }
};