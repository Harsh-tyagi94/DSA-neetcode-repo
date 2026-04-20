class Solution {
public:
    int reverse(int x) {
        int mod = 10;
        int isNegative = 1;
        if(x < 0) {
            isNegative = -1;
            x = x == INT_MIN ? abs(x+1) : abs(x);
        }
        long long res = 0;
        while(x > 0) {
            res = res*10 + (x%mod);
            if(res > INT_MAX || res < INT_MIN) return 0;
            x /= mod;
        }
        return isNegative*res;
    }
};
