class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == INT_MAX) return 0;
        int isNegative = 1;
        if(x < 0) isNegative = -1;
        x *= isNegative;

        string nums = to_string(x);
        int n = nums.length();
        long long res = nums[n-1]-'0';
        for(int i=n-2;i>=0;i--) {
            res = res*10 + (nums[i]-'0');
            if(res < INT_MIN || res > INT_MAX) return 0;
        }
        return res*isNegative;
    }
};