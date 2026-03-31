class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = 1e9;
        int res = INT_MAX;
        while(l<=r) {
            int mid = l + (r-l)/2;
            int splits = 1, sum = 0;
            for(int i=0;i<nums.size();i++) {
                sum += nums[i];
                if(sum > mid) {
                    splits += 1;
                    sum = nums[i];
                }
            }

            if(splits <= k) {
                res = min(res,mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};