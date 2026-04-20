class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size(), COL = matrix[0].size();
        int l = 0, r = ROW*COL-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int row = mid/COL, col = mid%COL;
            if(target == matrix[row][col]) return true;
            else if(target <= matrix[row][col]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};