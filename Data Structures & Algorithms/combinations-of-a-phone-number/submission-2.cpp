class Solution {
    vector<string> mapping;
public:
    vector<string> res;
    void solver(string digits, int index, string ans) {
        if(index == digits.size()) {
            res.push_back(ans);
            return;
        }

        for(char s:mapping[digits[index]-'2']) {
            solver(digits, index+1, ans+s);
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        char ch = 'a';
        for(int i=2;i<10;i++) {
            string vec = "";
            if(i == 7 || i == 9) {
                for(int j=0;j<4;j++) {
                    vec += ch;
                    ch += 1;
                }
            } else {
                for(int j=0;j<3;j++) {
                    vec += ch;
                    ch += 1;
                }
            }
            mapping.push_back(vec);
        }

        solver(digits, 0, "");
        return res;
    }
};