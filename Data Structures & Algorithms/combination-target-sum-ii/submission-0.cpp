class Solution {
private: 
    void back_track(vector<int>& candidates,vector<vector<int>>& vec,vector<int> v,int target,int idx){
        int n=candidates.size();
        if(idx==n){
            if(target==0){
                vec.push_back(v);
            }
            return;
        }
        //excluded
        int i=idx;
            while(i<n-1 && candidates[i]==candidates[i+1]){
                i++;
                if(i==n-1){
                    break;
                }
            }
        back_track(candidates,vec,v,target,i+1);

        //included
        int num=candidates[idx];
        if(target>=num){
            v.push_back(num);
            back_track(candidates,vec,v,target-num,idx+1);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vec;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        back_track(candidates,vec,v,target,0);
        return vec;
    }
};
