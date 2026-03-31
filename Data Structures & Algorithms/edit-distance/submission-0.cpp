class Solution {
public:
    int w1,w2;
    vector<vector<int>> dp;
    int helper(string word1, string word2,int i,int j) {
        if(j >= w2) {
            return w1-i;
        }
        if(i >= w1) {
            return w2-j;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(word1[i] == word2[j]) {
            return dp[i][j] = helper(word1,word2,i+1,j+1);
        }

        //del
        int del = helper(word1,word2,i+1,j);

        //insert or replace
        int ins = helper(word1,word2,i,j+1);

        //replace
        int rep = helper(word1,word2,i+1,j+1);

        return dp[i][j] = 1 + min({del,ins,rep});
    }
    int minDistance(string word1, string word2) {
        w1 = word1.length();
        w2 = word2.length();
        dp.resize(w1, vector<int>(w2,-1));
        return helper(word1,word2,0,0);
    }
};
