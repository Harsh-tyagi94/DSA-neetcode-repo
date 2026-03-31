class Solution {
    bool is_palindrome(string s,int l,int r) {
        while(l<=r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.length();
        for(int len=1;len<=n;len++) {
            for(int i=0;i<=n-len;i++) {
                if(is_palindrome(s,i,len+i-1)) cnt++;
            }
        }
        return cnt;
    }
};
