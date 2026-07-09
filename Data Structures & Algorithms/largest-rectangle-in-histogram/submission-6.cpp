class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, int>> Stack;
        Stack.push_back({-1, -1});
        int res = 0;
        for(int i=0;i<n;i++) {
            int temp = i;
            while(Stack.back().second >= heights[i]) {
                auto [idx, h] = Stack.back(); Stack.pop_back();
                res = max(res, h * (i - idx));
                temp = idx;
            }
            Stack.push_back({temp, heights[i]});
        }

        while(Stack.size() > 1) {
            auto [idx, h] = Stack.back(); Stack.pop_back();
            res = max(res, h * (n - idx));
        }
        return res;
    }
};