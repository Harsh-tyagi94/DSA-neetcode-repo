class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        int m = times.size();

        for(int i=0;i<m;i++) {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];

            adj[u].push_back({v,t});
        }

        queue<pair<int,int>> q;
        vector<int> dist(n+1,INT_MAX);

        q.push({k,0});
        dist[k] = 0;
        dist[0] = 0;

        while(!q.empty()) {
            auto [node,cost] = q.front();
            q.pop();

            if(cost > dist[node]) continue;

            for(const auto& [nei,dis]:adj[node]) {
                int newcost = dis+cost;
                if(dist[nei] > newcost) {
                    dist[nei] = newcost;
                    q.push({nei,newcost});
                }
            }
        }

        int res = 0;
        for (auto time : dist) {
            res = max(res, time);
        }
        return res == INT_MAX ? -1 : res;
    }
};
