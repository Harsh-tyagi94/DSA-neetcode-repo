class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for(string s:strs) {
            int len = s.length();
            res += to_string(len) + ',' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int index = 0;
        while(index < s.length()) {
            int t = index;
            string st = "";
            while(s[index] != ',') {
                st += s[index];
                index += 1;
            }
            index += 1;
            int len = stoi(st);
            res.push_back(s.substr(index, len));
            index += len;
        }
        return res;
    }
};
