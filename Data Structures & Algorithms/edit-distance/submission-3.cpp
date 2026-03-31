class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();

        vector<vector<int>> dp(w1+1,vector<int>(w2+1,0));
        for(int i=0;i<=w1;i++) dp[i][w2] = w1-i;
        for(int j=0;j<=w2;j++) dp[w1][j] = w2-j;

        for(int i=w1-1;i>=0;i--) {
            for(int j=w2-1;j>=0;j--) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
                }
            }
        }

        return dp[0][0];
    }
};
