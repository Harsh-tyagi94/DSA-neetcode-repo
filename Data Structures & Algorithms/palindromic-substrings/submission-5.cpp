class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            while(i > 0 && s[i] == s[i-1]) continue;
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res += 1;
                l--;
                r++;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res += 1;
                l--;
                r++;
            }
        }
        return res;
    }
};