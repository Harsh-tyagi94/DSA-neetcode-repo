class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, prev = -1;

        unordered_map<char,int> ump;

        for(int i=0;i<s.length();i++) {
            if(ump.find(s[i]) != ump.end()) {
                prev = max(prev,ump[s[i]]);
            }
            ump[s[i]] = i;
            res = max(res,i-prev);
        }
        return res;
    }
};
