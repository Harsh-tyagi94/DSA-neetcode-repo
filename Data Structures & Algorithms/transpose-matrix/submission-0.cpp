class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> mat(col, vector<int>(row));
        for(int c=0;c<col;c++) {
            for(int r=0;r<row;r++) {
                mat[c][r] = matrix[r][c];
            }
        }
        return mat;
    }
};