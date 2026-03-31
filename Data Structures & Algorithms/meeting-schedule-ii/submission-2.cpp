/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval& a,const Interval& b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> vec;
        vec.push_back(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            bool val=true;
            for(int j=0;j<vec.size();j++){
                if(vec[j]<=intervals[i].start){
                    vec[j]=intervals[i].end;
                    val=false;
                    break;
                }
            }
            if(val){
                vec.push_back(intervals[i].end);
            }
        }
        return vec.size();
    }
};
