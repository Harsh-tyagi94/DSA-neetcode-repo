class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        int offset = 1;
        for(int i=1;i<=n;i++) {
            if(offset*2 == i) offset = i;
            res[i] = 1 + res[i-offset];
        }
        return res;
    }
};

/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
|
0 1 1 2 1 2 2 3 1 2 2  3  2  3  3  4

8*2 == 16 -- 
dp[8] = 1 + dp[0]
*/
