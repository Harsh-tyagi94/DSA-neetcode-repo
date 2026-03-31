class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;

        vector<int> prefix(n),suffix(n);

        int i=0;

        while(i<n) {
            int l=i-1;
            while(l>=0 && heights[l] >= heights[i]) {
                l--;
            }
            prefix[i] = l+1;

            l = i+1;
            while(l<n && heights[l] >= heights[i]) {
                l++;
            }
            suffix[i] = l-1;

            res = max(res,(heights[i])*(suffix[i]-prefix[i]+1));
            while(i+1 < n && heights[i] == heights[i+1]) {
                i++;
            }
            i++;
        }
        return res;
    }
};
