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
                for(int k=j+1;k<n;k++) {
                    if(k > j+1 && k < n && nums[k-1] == nums[k]) continue;
                    for(int l=k+1;l<n;l++) {
                        if(l > k+1 && l < n && nums[l-1] == nums[l]) continue;
                        if((long long)nums[i]+nums[j]+nums[k]+nums[l] == target) res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
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