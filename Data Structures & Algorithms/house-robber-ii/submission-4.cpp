class Solution {
public:
    int robbing(vector<int>& nums,int l,int e) {
        if(e-l == 1) return nums[l];
        int rob_first = 0, rob_second = 0;

        for(l;l<e;l++) {
            int t = max(rob_second, nums[l] + rob_first);
            rob_first = rob_second;
            rob_second = t;
        }

        return max(rob_first, rob_second);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robbing(nums,0,n-1), robbing(nums,1,n));
    }
};
