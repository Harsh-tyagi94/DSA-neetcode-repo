class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1, maxi = 1;
        int res = nums[0];
        for(auto num:nums) {
            int temp = mini;
            mini = min({num,temp*num,maxi*num});
            maxi = max({num,temp*num,maxi*num});
            res = max({res,maxi});
        }
        return res;
    }
};