class Solution {
private:
    void helper(int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i==m || j==n){
            dp[i][j]=0;
            return;
        }
        if(dp[i][j]!=-1){
            return;
        }
        dp[i][j]=0;
        helper(m,n,i+1,j,dp);
        dp[i][j]+=dp[i+1][j];
        helper(m,n,i,j+1,dp);
        dp[i][j]+=dp[i][j+1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        dp[m-1][n-1]=1;
        helper(m,n,0,0,dp);
        return dp[0][0];
    }
};