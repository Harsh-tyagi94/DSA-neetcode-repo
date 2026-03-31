class Solution {
public:
    vector<vector<int>> adj;

    bool dfs(int node,int parent,unordered_set<int>& visited) {
        if(visited.count(node)) return false;
        visited.insert(node);

        for(int nei:adj[node]) {
            if(nei == parent) continue;

            if(!dfs(nei,node,visited)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        adj.resize(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited(n);

        if(!dfs(0,-1,visited)) return false;

        return visited.size() == n;
    }
};
