class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        while(true) {
            if(n == 1) return true;
            if(uset.count(n)) break;
            uset.insert(n);
            string num = to_string(n);
            long long res = 0;
            for(char c:num) res += (c-'0')*(c-'0');
            n = res;
        }
        return false;
    }
};