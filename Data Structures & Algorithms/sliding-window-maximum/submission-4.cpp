class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> qmax;
        int index = 0;
        while(index < k) {
            qmax.push({nums[index], index});
            index += 1;
        }
        vector<int> res;
        res.push_back(qmax.top().first);
        while(index < nums.size()) {
            qmax.push({nums[index], index});
            while(index - k >= qmax.top().second) {
                qmax.pop();
            }
            res.push_back(qmax.top().first);
            index += 1;
        }
        return res;
    }
};