class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0, res = 0;
        int l=0;
        vector<int> ch(26,0);

        for(int r=0;r<s.length();r++) {
            ch[s[r]-'A']++;
            maxf = max(maxf,ch[s[r]-'A']);

            while((r-l+1)-maxf > k) {
                ch[s[l]-'A']--;
                l++;
            }

            res = max(res,r-l+1);
        }

        return res;
    }
};
