class Solution {
public:
    typedef tuple<int,int,int> T;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto f:flights) {
            adj[f[0]].push_back({f[1],f[2]});
        }
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0,src,k});

        while(!pq.empty()) {
            int cost = get<0>(pq.top());
            int u = get<1>(pq.top());
            int stops = get<2>(pq.top());

            pq.pop();

            if(u == dst) return cost;

            for(auto nei:adj[u]) {
                int newcost = cost+nei.second;

                if(nei.first != dst && stops == 0) continue;
                int newstops = stops;
                if(nei.first != dst) {
                    newstops--;
                }
                pq.push({newcost,nei.first,newstops});
            }
        }
        return -1;
    }
};
