class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int prev = 0, res = 0, n = s.length();
        for(int i=0;i<n;i++) {
            while(uset.count(s[i])) {
                res = max(res, i - prev);
                uset.erase(s[prev]);
                prev += 1;
            }
            uset.insert(s[i]);
        }
        res = max(res, n-prev);
        return res;
    }
};