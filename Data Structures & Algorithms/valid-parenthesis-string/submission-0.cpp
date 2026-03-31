class Solution {
public:
    bool checkValidString(string s) {
        int opening_parenthesis_count = 0, closing_parenthesis_count = 0;

        for(char a:s) {
            if(a == '(') {
                opening_parenthesis_count++;
                closing_parenthesis_count++;
            }
            else if(a == ')') {
                opening_parenthesis_count--;
                closing_parenthesis_count--;
            }
            else {
                opening_parenthesis_count--;
                closing_parenthesis_count++;
            }

            if(closing_parenthesis_count < 0) return false;
            if(opening_parenthesis_count < 0) opening_parenthesis_count = 0;
        }

        return opening_parenthesis_count == 0;
    }
};

/*
s = (((*)(*)
           ^

opening_parenthesis_count = 4
closing_parenthesis_count = 3
star_count = 2
*/