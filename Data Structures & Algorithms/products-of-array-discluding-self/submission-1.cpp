class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {0};
        vector<int> prefix(n+1, 1),suffix(n+1, 1);

        for(int i=0;i<n;i++) {
            prefix[i+1] = nums[i]*prefix[i];
            suffix[n-1-i] = nums[n-1-i]*suffix[n-i];
        }

        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(prefix[i]*suffix[i+1]);
        }
        return res;
    }
};