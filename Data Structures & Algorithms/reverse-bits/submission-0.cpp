class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = "";
        for(int i = 0; i < 32; i++) {
            if( (n & 1) > 0 ) s += '1';
            else s += '0';
            n = n>>1;
        }
        
        uint32_t res = 0;
        int cnt = 1;
        for(int i=0;i<32;i++) {
            if(s[31-i] == '1') res += cnt;
            cnt *= 2;
        }
        return res;
    }
};
