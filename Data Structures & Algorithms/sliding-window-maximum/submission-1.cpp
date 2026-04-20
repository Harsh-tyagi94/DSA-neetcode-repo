class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> qmax;
        vector<int> res;
        int prev = 0;
        for(int i=0;i<k;i++) {
            qmax.push({nums[i], i});
        }
        res.push_back(qmax.top().first);
        for(int i=k;i<nums.size();i++) {
            qmax.push({nums[i], i});
            while(i - qmax.top().second + 1 > k) qmax.pop();
            res.push_back(qmax.top().first);
        }
        return res;
    }
};