class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = 0;

        vector<int> spiral_order_list;
        while(r < row && c < col) {
            // right -- c < col
            for(int j=c;j<col;j++) {
                spiral_order_list.push_back(matrix[r][j]);
            }
            r++;

            // down -- r < row
            for(int i=r;i<row;i++) {
                spiral_order_list.push_back(matrix[i][col-1]);
            }
            col--;

            if (!(r < row && c < col)) {
                break;
            }

            // left -- j > c
            for(int j=col-1;j>=c;j--) {
                spiral_order_list.push_back(matrix[row-1][j]);
            }
            row--;

            // upper -- i > r
            for(int i=row-1;i>=r;i--) {
                spiral_order_list.push_back(matrix[i][c]);
            }
            c++;
        }

        return spiral_order_list;
    }
};
