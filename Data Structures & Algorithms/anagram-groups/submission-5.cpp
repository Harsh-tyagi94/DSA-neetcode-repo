class Solution {
public:
    string build_string(string strs) {
        vector<int> character(26, 0);
        for(int i=0;i<strs.length();i++) {
            character[strs[i]-'a'] += 1;
        }
        string ans = to_string(character[0]);
        for(int i=1;i<26;i++) {
            ans += "," + to_string(character[i]);
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
