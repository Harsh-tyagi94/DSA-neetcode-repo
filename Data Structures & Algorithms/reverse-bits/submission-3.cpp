class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<uint32_t> reversebit(32, 0);

        int index = 0;
        while(n > 0) {
            if(n & 1) reversebit[31-index] = 1;
            n >>= 1;
            index += 1;
        }
        uint32_t res = 0;
        long long cnt = 1;
        for(int i=0;i<32;i++) {
            if(reversebit[i] == 1) res += cnt;
            cnt *= 2;
        }
        return res;
    }
};
