class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int slowptr = nums[0];
        int fastptr = nums[slowptr];

        while(slowptr != fastptr) {
            slowptr = nums[slowptr];
            fastptr = nums[nums[fastptr]];
        }

        slowptr = nums[0];
        fastptr = nums[fastptr];
        while(slowptr != fastptr) {
            slowptr = nums[slowptr];
            fastptr = nums[fastptr];
        }

        return slowptr;
    }
};