class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        pair<int,int> res = {-1,INT_MAX};
        unordered_map<char,int> target;

        for(char num:t) {
            target[num]++;
        }

        unordered_map<char,int> window;
        int need  = target.size(), have = 0;
        int prev = 0, max_len = INT_MAX;
        for(int i=0;i<s.size();i++) {
            window[s[i]]++;
            if(target.count(s[i]) && target[s[i]] == window[s[i]]) {
                have++;
            }

            while(need == have && prev <= i) {
                if(res.second > i-prev+1) {
                    res = {prev,i-prev+1};
                }
                window[s[prev]]--;

                if(target.count(s[prev]) && target[s[prev]] > window[s[prev]]) have--;
                prev++;
            }
        }

        return res.first == -1 ? "" : s.substr(res.first, res.second);
    }
};