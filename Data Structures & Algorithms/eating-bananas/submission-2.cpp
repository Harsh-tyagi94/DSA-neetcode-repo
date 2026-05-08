class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while(l<=r) {
            int mid = l + (r-l)/2;
            long long time = 0;
            for(auto p:piles) {
                time += ceil((double)p/mid);
            }
            if(time <= h) {
                res = min(res, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};