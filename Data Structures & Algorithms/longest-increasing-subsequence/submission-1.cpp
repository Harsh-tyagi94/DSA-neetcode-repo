class Solution {
private:
    int solve(vector<vector<int>>& dp,vector<int>& nums,int i,int j,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }

        //no add 
        int NA=solve(dp,nums,i+1,j,n);
        //add
        int A=0;
        if(j==-1 || nums[i]>nums[j]){
            A = 1 + solve(dp,nums,i+1,i,n);
        }

        return dp[i][j+1] = max(NA,A);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(dp,nums,0,-1,n);
    }
};
