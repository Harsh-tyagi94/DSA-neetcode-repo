class Solution {
private:
    void backtrack(vector<int>& nums,vector<int> v,vector<vector<int>> &vec,int i){
        if(i==nums.size())
        {
            vec.push_back(v);
            return;
        }
        //exclude 
        backtrack(nums,v,vec,i+1);
        v.push_back(nums[i]);
        backtrack(nums,v,vec,i+1);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        backtrack(nums,v,vec,0);
        return vec;
    }
};