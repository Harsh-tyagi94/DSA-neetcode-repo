class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int sz_a = a.size(), sz_b = b.size(), c = 0;
        for(int i=0;i<max(sz_a, sz_b);i++) {
            int abit = (i< sz_a && a[sz_a-1-i] == '1') ? 1 : 0;
            int bbit = (i < sz_b && b[sz_b-1-i] == '1') ? 1 : 0;
            res += (abit^bbit^c)+'0';
            c = (abit+bbit+c >= 2) ? 1 : 0;
        }

        if(c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};