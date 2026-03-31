class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char,int> ump,ch;
        for(auto character:t) {
            ump[character]++;
        }

        int have = 0,need = ump.size();
        int left = 0;
        int max_len = INT_MAX;
        pair<int,int> res = {-1,-1};

        for(int right=0;right<n;right++) {
            char a = s[right];
            ch[a]++;
            if(ump.find(a)!=ump.end() && ump[a] == ch[a]) have++;

            while(have == need && left<=right) {
                if(right - left + 1 < max_len) {
                    max_len = right-left+1;
                    res = {left,max_len};
                }
                ch[s[left]]--;
                if(ump.find(s[left])!=ump.end() && ump[s[left]] > ch[s[left]]) have--;

                left++;
            }
        }
        return max_len == INT_MAX ? "":s.substr(res.first,res.second);
    }
};
