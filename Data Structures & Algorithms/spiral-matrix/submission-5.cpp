class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int row1 = 0, row2 = m-1;
        int col1 = 0, col2 = n-1;

        while(res.size() < m*n) {
            for(int j=col1;j<=col2;j++) {
                res.push_back(matrix[row1][j]);
            }

            row1 += 1;
            for(int i=row1;i<=row2;i++) {
                res.push_back(matrix[i][col2]);
            }

            if(res.size() == m*n) return res;

            col2 -= 1;
            for(int j=col2;j>=col1;j--) {
                res.push_back(matrix[row2][j]);
            }

            row2 -= 1;
            for(int i=row2;i>=row1;i--) {
                res.push_back(matrix[i][col1]);
            }

            col1 += 1;
        }

        return res;
    }
};

/*
res = [1 2 3 6 9]

row1 = 1
row2 = 2
col1 = 0
col2 = 1

matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

*/
