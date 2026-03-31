class Solution {
public:
    long long findNumber(string num) {
        long long prod = 1;
        long long number = 0;
        for(int i=num.length()-1;i>=0;i--) {
            long long n = num[i]-'0';
            number += n*prod;
            prod *= 10;
        }
        return number;
    }
    string multiply(string num1, string num2) {
        long long first_num = findNumber(num1);
        long long second_num = findNumber(num2);
        
        long long product = first_num*second_num;
        if(product == 0) return "0";
        string res = "";

        long long pow = 10;
        long long prev_pow = 1;
        while(product >= prev_pow) {
            long long modulo_rem = product%pow;
            int number = modulo_rem/prev_pow;
            char c = number + '0';
            res += c;
            pow *= 10;
            prev_pow *= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
