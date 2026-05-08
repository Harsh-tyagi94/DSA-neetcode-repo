/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int leftMountainArr(int target, MountainArray &mountainArr, int l, int r) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return INT_MAX;
    }
    int rightMountainArr(int target, MountainArray &mountainArr, int l, int r) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) {
                return mid;
            } else if(mountainArr.get(mid) > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return INT_MAX;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length()-1;
        int l = 0, r = n;
        int index = -1;
        while(l < r) {
            int mid = l + (r-l)/2;
            int leftval = mountainArr.get(mid-1);
            int midval = mountainArr.get(mid);
            int rightval = mountainArr.get(mid+1);

            if(midval > leftval && midval > rightval) {
                index = mid;
                break;
            } else if(midval > leftval && midval < rightval) {
                l = mid;
            } else if(midval < leftval && midval > rightval) {
                r = mid;
            } else {
                l += 1;
            }
        }
        int res = leftMountainArr(target, mountainArr, 0, index);
        res = min(res, rightMountainArr(target, mountainArr, index, n));

        return res == INT_MAX ? -1 : res;
    }
};


/*
mountainArr = [3, 5, 3, 2, 0]
               ^

*/