class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int max_area = 0;
        for(int i=0;i<heights.size();i++) {
            int start = i;
            while(!st.empty() && st.top().first > heights[i]) {
                max_area = max(max_area,st.top().first * (i-st.top().second));
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i],start});
        }
        while (!st.empty()) {
            int height = st.top().first;
            int index = st.top().second;
            max_area = max(max_area, height * (static_cast<int>(heights.size()) - index));
            st.pop();
        }

        return max_area;
    }
};
