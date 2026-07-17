class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 1;
        int cnt = 0;
        while(mask <= n) {
            if(mask & n) cnt += 1;
            mask <<= 1;
        }
        return cnt;
    }
};
