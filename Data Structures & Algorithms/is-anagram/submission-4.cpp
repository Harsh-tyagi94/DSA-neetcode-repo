class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> characters(26, 0);
        for(int i=0;i<s.length();i++) {
            characters[s[i]-'a'] += 1;
            characters[t[i]-'a'] -= 1;
        }

        for(int i=0;i<26;i++) {
            if(characters[i] != 0) return false;
        }
        return true;
    }
};
