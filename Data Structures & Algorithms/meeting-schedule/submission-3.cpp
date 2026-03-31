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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const Interval& a,const Interval& b) {
            return a.end < b.end;
        });

        int finish = 0;
        for(auto [s,e]:intervals) {
            if(finish > s) return false;
            finish = e;
        }
        return true;
    }
};
