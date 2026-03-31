class Solution {
public:
    vector<vector<string>> res;
    bool is_pal(string st) {
        int l=0, r=st.length()-1;
        while(l<r) {
            if(st[l] != st[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(string s, int i, vector<string>& vec) {
        if(i == s.length()) {
            res.push_back(vec);
            return;
        }

        string num = "";
        for(int index=i;index<s.length();index++) {
            num += s[index];
            if(is_pal(num)) {
                vec.push_back(num);
                helper(s, index+1, vec);
                vec.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        helper(s,0,vec);
        return res;
    }
};
