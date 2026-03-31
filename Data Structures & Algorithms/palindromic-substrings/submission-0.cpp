class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),max_cnt=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            //odd length
            while(l>=0 && r<n && s[l]==s[r]){
                max_cnt=max_cnt+1;
                l--;
                r++;
            }
            //even length
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                max_cnt=max_cnt+1;
                l--;
                r++;
            }
        }
        return max_cnt;
    }
};