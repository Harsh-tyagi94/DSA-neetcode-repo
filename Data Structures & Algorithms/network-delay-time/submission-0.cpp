class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> ump;
        for(auto t:times) {
            ump[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> distance(n+1,INT_MAX);
        distance[0] = 0;
        q.push({0,k});
        distance[k] = 0;

        while(!q.empty()) {
            auto [dist, node] = q.top();
            q.pop();

            if (dist > distance[node]) continue;

            for(auto mp:ump[node]) {
                int newdist = dist + mp.second;
                if(distance[mp.first] > newdist) {
                    distance[mp.first] = newdist;
                    q.push({newdist,mp.first});
                }
            }
        }
        int res = 0;
        for(auto d:distance) {
            if (d == INT_MAX) return -1;
            res = max(res,d);
        }
        return res;
    }
};