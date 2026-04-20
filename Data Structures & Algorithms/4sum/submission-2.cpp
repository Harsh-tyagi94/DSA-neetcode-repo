class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++) {
            if(i > 0 && i < n && nums[i-1] == nums[i]) continue;
            for(int j=i+1;j<n;j++) {
                if(j > i+1 && j < n && nums[j-1] == nums[j]) continue;
                int l = j+1, r = n-1;
                while(l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l += 1;
                        r -= 1;
                        while(l < r && l > j+1 && l < n && nums[l-1] == nums[l]) l += 1;
                        while(l < r && r > j+1 && r < n-1 && nums[r] == nums[r+1]) r -= 1;
                    } else if(sum > target) r -= 1;
                    else l += 1;
                }
            }
        }
        return res;
    }
};


/*
nums = [-3 0 1 2 3 3]
         ^   ^ ^ ^

*/