class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+3, INT_MIN);
        dp[n] = 0;

        for(int i=n-1;i>=0;i--) {
            int value = 0;
            for(int k=0;k<3 && k+i<n;k++) {
                value += stoneValue[i+k];
                dp[i] = max(dp[i], value - dp[i+k+1]);
            }
        }
        
        if(dp[0] == 0) return "Tie";
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};