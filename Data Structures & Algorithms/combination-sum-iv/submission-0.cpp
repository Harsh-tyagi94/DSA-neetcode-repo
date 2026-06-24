class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> dp(target+1, 0);
        dp[0] = 1;

        for(int t=1;t<=target;t++) {
            for(int i=0;i<n && t>=nums[i];i++) {
                dp[t] += dp[t-nums[i]];
                if (dp[t] > INT_MAX) dp[t] = 0;
            }
        }

        return (int)dp[target];
    }
};


/*
0 -> 0
1 -> 0
2 -> (2) -> 1
3 -> (3) -> 1
4 -> (2,2)/(4)

*/