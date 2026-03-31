class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        // return helper(word1, word2, 0, 0);

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int i=0;i<=m;i++) {
            dp[i][n] = m-i;
        }
        for(int j=0;j<=n;j++) {
            dp[m][j] = n-j;
        }

        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};
