class Solution {
private:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }

        sort(intervals.begin(),intervals.end(),cmp);

        int ans=0,newinterval=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(newinterval>intervals[i][0]){
                ans++;
            }
            else{
                newinterval=intervals[i][1];
            }
        }
        return ans;
    }
};