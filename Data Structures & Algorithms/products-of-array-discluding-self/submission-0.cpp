class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocount=0,sizes=nums.size();
        vector<int> res(sizes,0);
        long long product=1;
        for(auto n:nums){
            if(n==0){
                zerocount+=1;
                if(zerocount>=2){
                    return res;
                }
            }
            else{
                product=product*n;
            }
        }
        for(int i=0;i<sizes;i++){
            if(zerocount==0){
                res[i]=(product/nums[i]);    
            }
            else{
                if(nums[i]==0){
                    res[i]=product;
                }
            }
        }
        return res;
    }
};