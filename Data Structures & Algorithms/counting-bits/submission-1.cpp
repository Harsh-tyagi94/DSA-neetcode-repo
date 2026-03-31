class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++) {
            int m = i;
            while(m > 0) {
                if(m & 1) res[i] += 1;
                m >>= 1;
            }
        }
        return res;
    }
};
