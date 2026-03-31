class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // make reverse of every column
        for(int col=0;col<n;col++) {
            for(int row=0;row<n/2;row++) {
                swap(matrix[row][col], matrix[n-1-row][col]);
            }
        }

        // now take transpose of matrix
        for(int row=0;row<n;row++) {
            for(int col=row+1;col<n;col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        return;
    }
};
