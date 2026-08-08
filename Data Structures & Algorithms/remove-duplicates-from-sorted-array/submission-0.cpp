class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        for(int i=1;i<n;i++) {
            if(nums[i] != nums[i-1]) {
                if(i>k) nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }
};