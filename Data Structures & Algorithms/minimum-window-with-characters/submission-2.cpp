class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> res = {INT_MAX, -1};
        unordered_map<char, int> window, target;
        for(char st:t) {
            target[st] += 1;
        }
        int have = target.size(), need = 0, prev = 0;
        for(int i=0;i<s.length();i++) {
            window[s[i]] += 1;
            if(window[s[i]] == target[s[i]]) need += 1;
            while(have == need) {
                if(res.first > i - prev + 1) res = {i - prev + 1, prev};
                window[s[prev]] -= 1;
                if(window[s[prev]] < target[s[prev]]) need -= 1;
                prev += 1;
            }
        }
        return res.second == -1 ? "" : s.substr(res.second, res.first);
    }
};