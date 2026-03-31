class NumMatrix {
public:
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        sumMatrix.resize(m+1, vector<int>(n+1,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                sumMatrix[i+1][j+1] = matrix[i][j] + sumMatrix[i+1][j] + sumMatrix[i][j+1] - sumMatrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int lu_c = sumMatrix[row1][col1];
        int ld_c = sumMatrix[row2+1][col1];
        int ru_c = sumMatrix[row1][col2+1];
        int rd_c = sumMatrix[row2+1][col2+1];
        return rd_c - ru_c - ld_c + lu_c;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */