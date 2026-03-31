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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for(int idx=1;idx<intervals.size();idx++){
            if(intervals[idx].start<intervals[idx-1].end){
                return false;
            }
        }
        return true;
    }
};
