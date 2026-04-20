class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int res = nums[0];
        while(l <= r) {
            int mid = l + (r-l)/2;
            res = min(res, nums[mid]);
            if(nums[mid] < nums[r]) r = mid - 1;
            else l = mid + 1;
        }
        return res;
    }
};