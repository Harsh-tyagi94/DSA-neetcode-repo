class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=0,res=0;
        while(h<n-1){
            int maxjump=0;
            for(int i=l;i<=h;i++){
                maxjump=max(maxjump,i+nums[i]);
            }
            l=h+1;
            h=maxjump;
            res++;
        }
        return res;
    }
};
