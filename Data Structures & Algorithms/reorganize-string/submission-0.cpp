class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> characters(26, 0);
        for(int i=0;i<n;i++) {
            characters[s[i]-'a'] += 1;
        }

        if(*max_element(characters.begin(), characters.end()) > (n+1)/2) return "";
        priority_queue<pair<int, char>> q;
        for(char ch='a';ch<='z';ch++) {
            if(characters[ch-'a']) q.push({characters[ch-'a'], ch});
        }

        string res = "";
        while(!q.empty()) {
            pair<int, char> r = q.top(); q.pop();
            res += r.second;
            if(q.empty()) return res;
            pair<int, char> nr = q.top(); q.pop();
            res += nr.second;
            if(r.first > 1) q.push({r.first-1, r.second});
            if(nr.first > 1) q.push({nr.first-1, nr.second});
        }
        return res;
    }
};