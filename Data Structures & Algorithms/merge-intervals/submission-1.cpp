class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        sort(intervals.begin(),intervals.end());
        if(intervals.size()<=0){
            return vec;
        }
        int i=0,j=0;
        vec.push_back(intervals[i]);
        i=1;
        while(i<intervals.size()){
            if(intervals[i][0]>vec[j][1]){
                vec.push_back(intervals[i]);
                j++;
            }
            else{
                vec[j][0]=min(vec[j][0],intervals[i][0]);
                vec[j][1]=max(vec[j][1],intervals[i][1]);
            }
            i++;
        }
        return vec;
    }
};