class Solution {
public:
    string build_string(string strs) {
        vector<int> character(26, 0);
        for(int i=0;i<strs.length();i++) {
            character[strs[i]-'a'] += 1;
        }
        string ans = "";
        for(int i=0;i<26;i++) {
            while(character[i] > 0) {
                ans += (i + 'a');
                character[i] -= 1;
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(string s:strs) {
            string st = build_string(s);
            ump[st].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=ump.begin();it!=ump.end();it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
