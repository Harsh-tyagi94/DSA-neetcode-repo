class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();

        // take transpose of matrix
        for(int i=0;i<r;i++) {
            for(int j=i;j<r;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse each row
        for(int i=0;i<r;i++) {
            for(int j=0;j<r/2;j++) {
                swap(matrix[i][j],matrix[i][r-j-1]);
            }
        }
        return;
    }
};
