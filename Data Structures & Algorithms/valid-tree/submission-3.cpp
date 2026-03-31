class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int,int>> q;
        q.push({0,-1});
        unordered_set<int> visit;
        visit.insert(0);

        while(!q.empty()) {
            auto [node,parent] = q.front();
            q.pop();

            for(auto neig:adj[node]) {
                if(neig == parent) continue;

                if(visit.count(neig)) return false;
                visit.insert(neig);
                q.push({neig,node});
            }
        }

        return visit.size() == n;
    }
};
