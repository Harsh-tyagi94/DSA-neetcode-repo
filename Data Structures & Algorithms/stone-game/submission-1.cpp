class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                bool even = (r - l) % 2 == 0;
                int left = even ? piles[l] : 0;
                int right = even ? piles[r] : 0;
                if (l == r) {
                    dp[l][r] = left;
                } else {
                    dp[l][r] = max(dp[l + 1][r] + left, dp[l][r - 1] + right);
                }
            }
        }

        int total = accumulate(piles.begin(), piles.end(), 0);
        int aliceScore = dp[0][n - 1];
        return aliceScore > total - aliceScore;
    }
};