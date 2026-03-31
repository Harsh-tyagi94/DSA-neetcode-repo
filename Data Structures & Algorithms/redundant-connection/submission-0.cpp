class Solution {
private:
    int find_parent(int node,vector<int>& parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = find_parent(parent[node],parent);
    }
    void unionfind(vector<int>& edge,vector<int>& parent,vector<int>& rank,vector<int>& res) {
        int u = find_parent(edge[0],parent);
        int v = find_parent(edge[1],parent);

        if(u == v) {
            res.push_back(edge[0]);
            res.push_back(edge[1]);
        }
        else if(rank[u] == rank[v]) {
            parent[v] = u;
            rank[u]++;
        }
        else if(rank[u] != rank[v]) {
            if(rank[u] > rank[v]) {
                parent[v] = u;
            }
            else{
                parent[u] = v;
            }
        }
        return;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n+1);
        vector<int> rank(n+1,0);
        for(int i=0 ; i<=n ; i++) {
            parents[i] = i;
        }
        vector<int> res;
        for(auto& edge:edges) {
            unionfind(edge,parents,rank,res);
        }
        return res;
    }
};
