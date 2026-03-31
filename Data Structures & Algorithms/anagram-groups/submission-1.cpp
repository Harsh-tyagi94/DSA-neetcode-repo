class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;

        for(int i=0;i<strs.size();i++) {
            // string s = strs[i];
            // sort(s.begin(),s.end());
            vector<int> cnt(26,0);
            for(auto s:strs[i]) {
                cnt[s-'a']++;
            }

            string new_char = to_string(cnt[0]);
            for(int j=1;j<26;j++) {
                new_char += ',' + cnt[j];
            }
            ump[new_char].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto it=ump.begin();it!=ump.end();it++) {
            vector<string> v;
            for(auto s:it->second) {
                v.push_back(s);
            }
            res.push_back(v);
        }
        return res;
    }
};
