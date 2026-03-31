class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0],maxi=1,mini=1;
        for(auto n:nums){
            int lastmaxi=maxi;
            maxi=max(n,max(n*maxi,n*mini));
            mini=min(n,min(n*lastmaxi,n*mini));
            res=max(maxi,res);
        }
        return res;
    }
};