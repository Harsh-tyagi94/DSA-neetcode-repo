class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_prod(n+1, 1), suffix_prod(n+1, 1);
        for(int i=0;i<n;i++) {
            prefix_prod[i+1] = prefix_prod[i]*nums[i];
            suffix_prod[n-1-i] = suffix_prod[n-i]*nums[n-1-i];
        }
        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(prefix_prod[i]*suffix_prod[i+1]);
        }
        return res;
    }
};
