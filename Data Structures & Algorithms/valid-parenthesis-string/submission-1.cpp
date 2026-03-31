class Solution {
public:
    bool checkValidString(string s) {
        vector<int> left,star;

        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') left.push_back(i);
            else if(s[i] == '*') star.push_back(i);
            else {
                if(left.empty() && star.empty()) return false;

                if(!left.empty()) left.pop_back();
                else star.pop_back();
            }
        }

        while(!left.empty() && !star.empty()) {
            if(left.back() > star.back()) return false;
            left.pop_back();
            star.pop_back();
        }

        return left.empty() ? true : false;
    }
};

/*
s = "(((*))()"
            ^

s = "*("
      ^

left = [1]
star = [0]

*/