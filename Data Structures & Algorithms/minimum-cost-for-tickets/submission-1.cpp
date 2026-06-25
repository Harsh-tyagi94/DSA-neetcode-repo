class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        int i = 0;

        for (int d = 1; d < 366; d++) {
            dp[d] = dp[d - 1];

            if (i == days.size()) {
                return dp[d];
            }

            if (d == days[i]) {
                dp[d] += costs[0];
                dp[d] = min(dp[d], costs[1] + dp[max(0, d - 7)]);
                dp[d] = min(dp[d], costs[2] + dp[max(0, d - 30)]);
                i++;
            }
        }
        return dp[365];
    }
};