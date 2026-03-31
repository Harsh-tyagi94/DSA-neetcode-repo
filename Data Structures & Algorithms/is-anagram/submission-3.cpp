class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> store(26,0);
        for(auto pt:s) {
            store[pt-'a']++;
        }
        for(auto pt:t) {
            if(store[pt-'a'] == 0)
            return false;
            store[pt-'a']--;
        }
        return true;
    }
};
