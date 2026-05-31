class Solution {
public:
    bool checkmatch(string s, string p, int m, int n, int i, int j) {
        if(j == n) return i == m;

        bool match = (i < m && p[j] == '.' || s[i] == p[j]);
        if(j+1 < n && p[j+1] == '*') {
            return checkmatch(s, p, m, n, i, j+2) || (match && checkmatch(s, p, m, n, i+1, j));
        } else if(match) return checkmatch(s, p, m, n, i+1, j+1);
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;

        for(int i=m;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                bool match = i < m && (p[j] == '.' || s[i] == p[j]);
                if(j+1 < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
                } else dp[i][j] = match && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};