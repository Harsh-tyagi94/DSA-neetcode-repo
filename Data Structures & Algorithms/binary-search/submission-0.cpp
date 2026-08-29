class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            int md = l+(r-l)/2;
            if(nums[md]==target) return md;
            else if(nums[md]<target) l=md+1;
            else r=md-1;
        }
        return -1;
    }
};
