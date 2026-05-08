class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        int k = 2;
        while(k <= n) {
            int a = n/k, b = n%k;
            int res = pow(a+1, b);
            res *= pow(a, k-b);
            ans = max(ans, res);
            k += 1;
        }
        return ans;
    }
};