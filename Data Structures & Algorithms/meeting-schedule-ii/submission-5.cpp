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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> time_schedule;

        for(Interval inter:intervals) {
            int s = inter.start, e = inter.end;
            time_schedule[s]++;
            time_schedule[e]--;
        }

        int days = 0;
        int res = 0;
        // for(auto i=time_schedule.begin();i!=time_schedule.end();i++) {
        //     days += i->second;
        //     res = max(res,days);
        // }

        for(pair<int,int> time:time_schedule) {
            days += time.second;
            res = max(res,days);
        }
        return res;
    }
};
