class Solution {
private:
    int helper(vector<int>& dp,string s,int idx){
        if(idx>=s.length()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        dp[idx]=0;
        //single
        int single=helper(dp,s,idx+1);
        int doubles=(idx+1<s.length() && s.substr(idx,2)<="26") ? helper(dp,s,idx+2) : 0;
        dp[idx]=single+doubles;
        return dp[idx];
    }
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return helper(dp,s,0);
    }
};