class Solution {
public:

    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    void mergeSort(vector<int>& nums,int l,int r) {
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);

        merge(nums,l,mid,r);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};