class Solution {
private:
    void solve(vector<vector<int>>& res,vector<int>& v1,vector<int>& nums){
        if(nums.size()<=0){
            res.push_back(v1);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> r=nums;
            v1.push_back(r[i]);
            r.erase(r.begin()+i);
            solve(res,v1,r);
            v1.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v1;
        vector<vector<int>> res;
        solve(res,v1,nums);
        return res;
    }
};