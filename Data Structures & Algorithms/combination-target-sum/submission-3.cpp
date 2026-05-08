class Solution {
private:
    void back_track(vector<vector<int>> &vec,vector<int> v,vector<int>& candidates,int target,int k){
        //someone solution beat >8.26%
        // if(index==candidates.size()){
        //     if(target==0){
        //         vec.push_back(v);
        //     }
        //     return;
        // }//to pick elements
        // if(candidates[index]<=target){
        //     v.push_back(candidates[index]);
        //     back_track(vec,v,candidates,target-candidates[index],index);
        //     v.pop_back();
        // }
        // back_track(vec,v,candidates,target,index+1);

        //that is what i think!  :my own solution beat 8.46%
        if(k==candidates.size() || target<0){
            return;
        }
        if(target==0){
            vec.push_back(v);
            return;
        }
        back_track(vec,v,candidates,target,k+1);
        v.push_back(candidates[k]);
        back_track(vec,v,candidates,target-candidates[k],k);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        vector<int> v;
        back_track(vec,v,candidates,target,0);
        return vec;
    }
};
