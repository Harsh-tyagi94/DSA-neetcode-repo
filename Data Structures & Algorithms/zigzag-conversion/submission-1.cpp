class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1 || numRows >= n)
            return s;
        int shift = 2*(numRows-1);
        string ciphertext;
        int idx = shift;
        for(int i=0;i<numRows;i++) {
            int k=i;
            if(i == 0 || i == numRows-1) {
                while(k<n) {
                    ciphertext += s[k];
                    k += shift;
                }
            } else {
                int j=--idx;
                while(k<n) {
                    ciphertext += s[k];
                    k += shift;
                    if(j<n) {
                        ciphertext += s[j];
                        j += shift;
                    }
                }
            }
        }
        return ciphertext;
    }
};