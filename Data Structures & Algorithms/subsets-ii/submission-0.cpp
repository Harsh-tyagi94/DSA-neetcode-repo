class Solution {
private:
        void back_track(vector<vector<int>> &vec,vector<int> v,vector<int>& nums,int idx){
            if(idx==nums.size()){
                vec.push_back(v);
                return;
            }
            //exclude
            int i=idx;
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
                if(i==nums.size()-1){
                    break;
                }
            }
            back_track(vec,v,nums,i+1);

            //include
            v.push_back(nums[idx]);
            back_track(vec,v,nums,idx+1);
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        sort(nums.begin(),nums.end());
        back_track(vec,v,nums,0);
        return vec;
    }
};
