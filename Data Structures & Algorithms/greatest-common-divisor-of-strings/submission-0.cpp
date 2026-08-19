class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        if (m < n) {
            swap(m, n);
            swap(str1, str2);
        }

        for (int l = n; l > 0; l--) {
            if (m % l != 0 || n % l != 0) {
                continue;
            }

            bool valid = true;
            for (int i = 0; i < m; i++) {
                if (str1[i] != str2[i % l]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (int i = l; i < n; i++) {
                if (str2[i] != str2[i % l]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return str2.substr(0, l);
            }
        }

        return "";
    }
};