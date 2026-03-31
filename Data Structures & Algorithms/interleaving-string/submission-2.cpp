class Solution {
private:
    bool helper(string s1, string s2, string s3, vector<vector<int>>& dp, int idx1, int idx2) {
        if (idx1 == s1.length() && idx2 == s2.length()) {
            return true;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        bool result = false;
        if (idx1 < s1.length() && s1[idx1] == s3[idx1 + idx2]) {
            result = helper(s1, s2, s3, dp, idx1 + 1, idx2);
        }
        if (idx2 < s2.length() && s2[idx2] == s3[idx1 + idx2]) {
            result = result || helper(s1, s2, s3, dp, idx1, idx2 + 1);
        }
        dp[idx1][idx2] = result;
        return result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) {
            return false;
        }
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        return helper(s1, s2, s3, dp, 0, 0);
    }
};