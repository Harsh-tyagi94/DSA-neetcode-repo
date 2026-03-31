// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();

//         int res = 0;
//         for(int i=0;i<n;i++) {
//             nums[i] ^= i+1;
//             res ^= nums[i];
//         }

//         return res;
//     }
// };


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int mask = 1;

        for(int i = 0; i < 32; i++) {
            int mask_cnt_from_nums = 0;

            for(int n : nums) {
                if(n & mask) mask_cnt_from_nums++;
            }

            int mask_cnt_upto_n = 0;
            for(int n = 0; n <= nums.size(); n++) {
                if(n & mask) mask_cnt_upto_n++;
            }

            if(mask_cnt_from_nums != mask_cnt_upto_n)
                res += mask;

            mask <<= 1;
        }

        return res;
    }
};