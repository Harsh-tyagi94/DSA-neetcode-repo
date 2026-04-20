class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        k %= n;
        k = n - k;
        for(int i=0;i<n;i++) {
            res.push_back(nums[(k+i)%n]);
        }
        nums = res;
    }
};