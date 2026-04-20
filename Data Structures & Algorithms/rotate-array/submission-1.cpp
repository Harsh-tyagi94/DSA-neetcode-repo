class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int left = n - k;
        for(int i=0;i<left/2;i++) {
            swap(nums[i], nums[left-i-1]);
        }
        for(int i=0;i<k/2;i++) swap(nums[i+left], nums[n-i-1]);

        left = 0;
        int right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left += 1;
            right -= 1;
        }
        return;
    }
};

/*
nums = [1,2,3,4,5,6,7,8]
k = 6;
left = 8 - 6 = 2
i -> 0 - 0
21
i -> 0 - 2
876543

34567812
*/