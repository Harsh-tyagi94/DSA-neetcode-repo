class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        for (int score = 1; score <= n; score++) {
            for (int draw = 1; draw <= maxPts; draw++) {
                if (score - draw >= 0 && score - draw < k) {
                    dp[score] += dp[score - draw] / maxPts;
                }
            }
        }

        double result = 0.0;
        for (int i = k; i <= n; i++) {
            result += dp[i];
        }

        return result;
    }
};