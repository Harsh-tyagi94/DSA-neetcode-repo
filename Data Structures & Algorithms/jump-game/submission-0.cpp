class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return true;
        }
        int maxjump=nums[0];
        for(int i=0;i<n;i++){
            if(maxjump>0){
                maxjump=max(maxjump-1,nums[i]);
                if(n-1<=i+maxjump){
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
};