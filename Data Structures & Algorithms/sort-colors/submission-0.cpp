class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> countSort(3,0);
        for(auto n:nums) {
            countSort[n]++;
        }

        int i = 0;
        for(int j=0;j<countSort.size();j++) {
            while(countSort[j]>0) {
                nums[i++] = j;
                countSort[j]--;
            }
        }
        return;
    }
};