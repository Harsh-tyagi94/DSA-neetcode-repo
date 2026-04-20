class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> taskCollection;

        for(int i = 0; i < tasks.size(); i++) {
            taskCollection.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort by enqueue time
        sort(taskCollection.begin(), taskCollection.end());

        // Min heap: {processingTime, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        long long time = 0;
        int index = 0;
        vector<int> res;

        while(index < tasks.size() || !pq.empty()) {

            if(pq.empty() && time < taskCollection[index][0]) {
                time = taskCollection[index][0];
            }

            while(index < tasks.size() && taskCollection[index][0] <= time) {
                pq.push({taskCollection[index][1], taskCollection[index][2]});
                index++;
            }

            auto [procTime, i] = pq.top();
            pq.pop();

            time += procTime;
            res.push_back(i);
        }

        return res;
    }
};