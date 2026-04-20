class Solution {
public:
    int hammingWeight(uint32_t n) {
        int set_bits = 0, mask = 1;
        while(n > 0) {
            if(n & mask) set_bits += 1;
            n >>= 1;
        }
        return set_bits;
    }
};
