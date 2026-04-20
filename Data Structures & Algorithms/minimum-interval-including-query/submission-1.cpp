class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<int> SortQueries = queries;
        sort(SortQueries.begin(),SortQueries.end());

        map<int,int> key_index_for_queries;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sorted_interval_with_endTime;

        int interval_index = 0;
        for(auto q:SortQueries) {
            while(interval_index < n && intervals[interval_index][0] <= q) {
                int start = intervals[interval_index][0];
                int end = intervals[interval_index][1];
                interval_index++;
                sorted_interval_with_endTime.push({end-start+1,end});
            }

            while(!sorted_interval_with_endTime.empty() && sorted_interval_with_endTime.top().second < q) {
                sorted_interval_with_endTime.pop();
            }

            key_index_for_queries[q] = sorted_interval_with_endTime.empty() ? -1 : sorted_interval_with_endTime.top().first;
        }

        for(int i=0;i<queries.size();i++) {
            int key = key_index_for_queries[queries[i]];
            queries[i] = key;
        }

        return queries;
    }
};