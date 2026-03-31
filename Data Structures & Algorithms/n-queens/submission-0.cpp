class Solution {
private:
    void back_track(vector<vector<string>>& vec,vector<string>& v,int n,int qidx,vector<int>& queen){
        if(qidx>=n){
            vec.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(IsSafe(qidx,i,queen)){
                queen[qidx]=i;
                string s(n,'.');
                s[i]='Q';
                v.push_back(s);
                back_track(vec,v,n,qidx+1,queen);
                v.pop_back();
                queen[qidx]=-1;
            }
        }
    }
    bool IsSafe(int qidx,int i,vector<int>& queen){
        for(int j=0;j<qidx;j++){
            if((queen[j]==i) || (abs(queen[j]-i)==abs(j-qidx)))
            return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<int> queen(n,-1);
        vector<string> v;
        back_track(vec,v,n,0,queen);
        return vec;
    }
};