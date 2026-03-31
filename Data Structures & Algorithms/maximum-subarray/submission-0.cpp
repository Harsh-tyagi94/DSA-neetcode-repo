class Solution {
private:
    int leftsolve(vector<int>& nums,int l,int mid){
        int maxsum=nums[mid];
        int sum=nums[mid];
        for(int i=mid-1;i>=l;i--){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
    int rightsolve(vector<int>& nums,int mid,int h){
        int maxsum=nums[mid];
        int sum=nums[mid];
        for(int i=mid+1;i<=h;i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
    int subarray(vector<int>& nums,int l,int h){
        if(l==h){
            return nums[l];
        }
        int mid=l+(h-l)/2;
        int left=subarray(nums,l,mid);
        int right=subarray(nums,mid+1,h);
        int leftsubsum=leftsolve(nums,l,mid);
        int rightsubsum=rightsolve(nums,mid+1,h);
        int crosssum=leftsubsum + rightsubsum;
        return max(left,max(right,crosssum));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return subarray(nums,0,nums.size()-1);
    }
};