class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //quick select 
        k=nums.size()-k;
        int left=0,right=nums.size()-1;
        while(left<right){
            int pivot=partition(nums,left,right);
            if(pivot>k){
                right=pivot-1;
            }
            else if(pivot<k){
                left=pivot+1;
            }
            else
            break;
        }
        return nums[k];
    }
private:
    int partition(vector<int>& nums,int left,int right){
        int pivot=nums[right],fill=left;
        for(int i=left;i<right;i++){
            if(nums[i]<=pivot){
                swap(nums[i],nums[fill++]);
            }
        }
        swap(nums[fill],nums[right]);
        return fill;
    }
};
