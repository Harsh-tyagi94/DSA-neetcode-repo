class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> bits(32, 0);
        for(int num:nums) {
            for(int i=0;i<32;i++) {
                bits[i] += (num >> i) & 1;
            }
        }

        int res = 0, n = nums.size();
        for(int i=0;i<32;i++) {
            if(bits[i] > n/2) res |= (1 << i);
        }
        return res;
    }
};