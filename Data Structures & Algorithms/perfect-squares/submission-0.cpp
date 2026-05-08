class Solution {
public:
    int numSquares(int n) {
        int highest_num = sqrt(n);
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i=1;i<=highest_num;i++) {
            int sqr = i*i;
            for(int nums=sqr;nums<=n;nums++) {
                dp[nums] = min(dp[nums], 1 + dp[nums-sqr]);
            }
        }

        return dp[n];
    }
};