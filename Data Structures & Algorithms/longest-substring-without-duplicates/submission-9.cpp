class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int res = 0;
        int prev = -1;

        for(int i=0;i<s.length();i++) {
            if(ump.find(s[i])!=ump.end()) {
                prev = max(prev,ump[s[i]]);
            }

            ump[s[i]] = i;

            res = max(res,i-prev);
        }

        return res;
    }
};
