class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<int> characters(26);
        for(int i=0;i<26;i++) {
            characters[order[i]-'a'] = i;
        }

        string key = words[0];
        for(int i=1;i<n;i++) {
            bool flag = true;
            for(int k=0;k<min(key.length(), words[i].length()) && flag;k++) {
                if(characters[key[k]-'a'] > characters[words[i][k]-'a']) return false;
                else if(characters[key[k]-'a'] < characters[words[i][k]-'a']) {
                    flag = false;
                }
            }

            if(flag && key.length() > words[i].length()) return false;
            key = words[i];
        }
        return true;
    }
};