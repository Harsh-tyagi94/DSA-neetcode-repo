class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> ump;
        int res=0,cnt=0;
        for(int i=0;i<n;i++){
            if(ump.find(s[i])!=ump.end() && ump[s[i]]>=cnt){
                cnt=ump[s[i]]+1;
            }
            res = max(i-cnt+1,res);
            ump[s[i]] = i;
        }
        return res;
    }
};