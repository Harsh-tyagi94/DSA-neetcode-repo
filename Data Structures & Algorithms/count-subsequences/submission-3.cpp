class Solution {
public:
    vector<vector<int>> dp;
    int subsequence(string s,string t,int i,int j) {
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int res = subsequence(s,t,i+1,j);
        if(s[i] == t[j])
        res += subsequence(s,t,i+1,j+1);

        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        if(s.length() < t.length()) return 0;
        dp.resize(s.length(), vector<int>(t.length(),-1));
        return subsequence(s,t,0,0);
    }
};