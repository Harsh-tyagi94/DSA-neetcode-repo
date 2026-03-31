class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0,h = m*n-1;

        while(l <= h) {
            int mid = l + (h-l)/2;

            int r = mid/n;
            int c = mid%n;

            if(target == matrix[r][c]) {
                return true;
            } else if(target > matrix[r][c]) {
                l = mid + 1;
            } else {
                h = mid-1;
            }
        }
        return false;
    }
};