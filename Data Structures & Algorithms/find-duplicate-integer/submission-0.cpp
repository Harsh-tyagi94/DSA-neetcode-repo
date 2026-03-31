class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowpt,fastpt;
        slowpt=nums[0];
        fastpt=nums[slowpt];
        while(slowpt!=fastpt){
            slowpt=nums[slowpt];
            fastpt=nums[nums[fastpt]];
        }
        slowpt=nums[0];
        fastpt=nums[fastpt];
        while(slowpt!=fastpt){
            slowpt=nums[slowpt];
            fastpt=nums[fastpt];
        }
        return slowpt;
    }
};
