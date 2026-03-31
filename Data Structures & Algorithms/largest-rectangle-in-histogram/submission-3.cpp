class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();

        for(int i=0;i<n;i++) {
            int prev = i, next = i+1;
            while(prev>=0 && heights[prev] >= heights[i]) prev--;
            while(next<n && heights[next] >= heights[i]) next++;

            res = max(res, heights[i] * (next-prev-1));
        }
        return res;
    }
};