class Solution {
public:
    int getSum(int a, int b) {
        int c = 0, sum = 0;
        for(int i=0;i<32;i++) {
            int bit_a = (a>>i)&1;
            int bit_b = (b>>i)&1;
            int curr_bit = bit_a^bit_b^c;
            c = (bit_a + bit_b + c) >= 2 ? 1 : 0;
            if(curr_bit) sum |= (1<<i);
        }
        return sum;
    }
};
