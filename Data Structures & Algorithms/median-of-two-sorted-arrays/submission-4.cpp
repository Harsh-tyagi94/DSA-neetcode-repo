class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total+1)/2;

        if(A.size() > B.size()) swap(A,B);
        int l = 0, r = A.size();
        while(l <= r) {
            int i = l + (r-l)/2;
            int j = half - i;

            int aleft = i > 0 ? A[i-1] : INT_MIN;
            int aright = i < A.size() ? A[i] : INT_MAX;
            int bleft = j > 0 ? B[j-1] : INT_MIN;
            int bright = j < B.size() ? B[j] : INT_MAX;

            if(aleft <= bright && aright >= bleft) {
                if(total%2) {
                    return max(aleft, bleft);
                }
                return (max(aleft, bleft) + min(aright, bright))/2.0;
            } else if(aleft > bright) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};
