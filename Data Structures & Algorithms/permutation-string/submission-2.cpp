class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> window(26, 0), target(26, 0);
        for(char s:s1) {
            target[s-'a'] += 1;
        }
        int prev = 0;
        for(int i=0;i<s2.length();i++) {
            window[s2[i]-'a'] += 1;
            while(window[s2[i]-'a'] > target[s2[i]-'a']) {
                window[s2[prev]-'a'] -= 1;
                prev += 1;
            }
            if(i - prev + 1 == s1.length()) return true;
        }
        return false;
    }
};