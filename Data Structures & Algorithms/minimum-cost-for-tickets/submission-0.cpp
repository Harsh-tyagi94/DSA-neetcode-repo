class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MAX;
            int j = i;
            for (int k = 0; k < 3; ++k) {
                while (j < n && days[j] < days[i] + (k == 0 ? 1 : k == 1 ? 7 : 30)) {
                    j++;
                }
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }

        return dp[0];
    }
};