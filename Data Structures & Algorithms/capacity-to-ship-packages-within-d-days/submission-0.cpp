class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 1e9;
        int res = 1e9;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int day = 1;
            int curr = 0;
            for(int i=0;i<weights.size();i++) {
                curr += weights[i];
                if(curr > mid) {
                    curr = weights[i];
                    day += 1;
                }
            }

            if(day > days) {
                l = mid + 1;
            } else {
                res = min(res, mid);
                r = mid - 1;
            }
        }

        return res;
    }
};

/*
weights=[2,4,6,1,3,10]
         ^
days=4

l=1, r = 11
mid = 6
days = 3
curr = 6

*/