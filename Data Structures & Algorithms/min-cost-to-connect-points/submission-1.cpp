class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>> ump;

        int m = points.size();

        for(int i=0;i<m;i++) {
            for(int j=i+1;j<m;j++) {
                int u1 = points[i][0];
                int v1 = points[i][1];
                int u2 = points[j][0];
                int v2 = points[j][1];
                ump[i].push_back({j,abs(u1-u2)+abs(v1-v2)});
                ump[j].push_back({i,abs(u1-u2)+abs(v1-v2)});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visit(m,false);
        int dist = 0;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [cost,node] = pq.top();
            pq.pop();

            if(visit[node]) {
                continue;
            }
            dist += cost;
            visit[node] = true;

            for(auto nei:ump[node]) {
                int newcost = nei.second;
                if(!visit[nei.first]) {
                    pq.push({newcost,nei.first});
                }
            }
        }

        return dist;
    }
};
