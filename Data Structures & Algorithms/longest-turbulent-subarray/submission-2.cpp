class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, n = arr.size();
        int index = 0;
        while(index < n-1) {
            // first case
            if(index < n-1 && arr[index] > arr[index+1]) {
                int ans = 1;
                while(index < n-1) {
                    if(arr[index] > arr[index+1]) ans += 1;
                    else break;
                    index += 1;
                    if(index < n-1 && arr[index] < arr[index+1]) ans += 1;
                    else break;
                    index += 1;
                }
                res = max(res, ans);
            } else if(index < n-1 && arr[index] < arr[index+1]) {
                int ans = 1;
                while(index < n-1) {
                    if(arr[index] < arr[index+1]) ans += 1;
                    else break;
                    index += 1;
                    if(index < n-1 && arr[index] > arr[index+1]) ans += 1;
                    else break;
                    index += 1;
                }
                res = max(res, ans);
            } else index += 1;
        }
        return res;
    }
};