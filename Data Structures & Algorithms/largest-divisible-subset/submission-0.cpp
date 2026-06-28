class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        parent[0] = 0;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    parent[i] = j;
                }
            }
        }

        pair<int,int> max_len_index = {0,-1};
        for(int i=0;i<n;i++) {
            if(dp[i] > max_len_index.first) max_len_index = {dp[i], i};
        }

        int len = max_len_index.first;
        int index = max_len_index.second;
        vector<int> res(len, -1);
        while(len > 0) {
            res[len-1] = nums[index];
            index = parent[index];
            len -= 1;
        }
        return res;

    }
};