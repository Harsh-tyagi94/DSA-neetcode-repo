class Solution {
private:
    int helper(string text1,string text2,int i,int j,int r,int l,vector<vector<int>>& dp){
        if(i>=r || j>=l){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+helper(text1,text2,i+1,j+1,r,l,dp);
        }
        else{
            ans=max(helper(text1,text2,i,j+1,r,l,dp),helper(text1,text2,i+1,j,r,l,dp));
        }
        return dp[i][j]=ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int r=text1.length(),l=text2.length();
        vector<vector<int>> dp(r,vector<int>(l,-1));
        return helper(text1,text2,0,0,r,l,dp);
    }
};
