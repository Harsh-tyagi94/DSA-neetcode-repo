class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> Stack;
        int res = 0, n = heights.size();
        Stack.push_back({-1, -1});
        for(int i=0;i<n;i++) {
            int t = i;
            while(Stack.back().first >= heights[i]) {
                t = Stack.back().second;
                res = max(res, Stack.back().first * (i - t));
                Stack.pop_back();
            }
            Stack.push_back({heights[i], t});
        }

        while(Stack.size() > 1) {
            res = max(res, Stack.back().first * (n - Stack.back().second));
            Stack.pop_back();
        }
        return res;
    }
};