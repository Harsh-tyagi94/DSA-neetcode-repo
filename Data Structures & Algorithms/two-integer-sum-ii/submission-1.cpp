class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // this is my unique sliding window solution
        // int n = numbers.size(), prev = 0;
        // for(int i=1;i<n;i++) {
        //     while(prev < i && numbers[prev] + numbers[i] > target) prev++;
        //     if(prev < i && numbers[prev] + numbers[i] == target) return {numbers[prev],numbers[i]};
        // }
        // return {};

        // two pointer
        int l = 0, r = numbers.size()-1;
        while(l<r) {
            if(numbers[l]+numbers[r] == target) return {l+1,r+1};
            else {
                if((numbers[l]+numbers[r] > target)) r--;
                else l++;
            }
        }
        return {};
    }
};
