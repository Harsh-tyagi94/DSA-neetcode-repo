class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i=1;i<m;i++) {
            int n = triangle[i].size();
            triangle[i][0] += triangle[i-1][0];
            triangle[i-1].push_back(INT_MAX);
            for(int j=1;j<n;j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }

        int mini = *min_element(triangle[m-1].begin(), triangle[m-1].end());
        return mini;
    }
};