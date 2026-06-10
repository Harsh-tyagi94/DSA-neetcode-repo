class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> array(n+1, -1);
        for(int num:nums) {
            if(num > 0 && num <= n) {
                array[num] = num;
            }
        }

        for(int i=1;i<n+1;i++) {
            if(array[i] == -1) {
                return i;
            }
        }
        return n+1;
    }
};