class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool is_row_zero = false, is_col_zero = false;
        int row = matrix.size(), col = matrix[0].size();

        for(int r=0;r<row;r++) {
            if(matrix[r][0] == 0) {
                is_col_zero = true;
                break;
            }
        }
        for(int c=0;c<col;c++) {
            if(matrix[0][c] == 0) {
                is_row_zero = true;
                break;
            }
        }

        for(int r=1;r<row;r++) {
            for(int c=1;c<col;c++) {
                if(matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for(int r=1;r<row;r++) {
            if(matrix[r][0] == 0) {
                for(int c=1;c<col;c++) {
                    matrix[r][c] = 0;
                }
            }
        }
        for(int c=1;c<col;c++) {
            if(matrix[0][c] == 0) {
                for(int r=1;r<row;r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        if(is_row_zero) {
            for(int c=0;c<col;c++) matrix[0][c] = 0;
        }
        if(is_col_zero) {
            for(int r=0;r<row;r++) matrix[r][0] = 0;
        }
    }
};
