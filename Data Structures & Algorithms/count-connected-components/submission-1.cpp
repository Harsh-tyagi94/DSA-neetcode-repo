class Solution {
private:
    int find_parent(int node,vector<int>& parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = find_parent(parent[node],parent);
    }
    void unionfind(vector<int>& edge,vector<int>& parent,vector<int>& rank) {
        int u = find_parent(edge[0],parent);
        int v = find_parent(edge[1],parent);

        if(u == v) {
            return;
        }
        else if(rank[u] == rank[v]) {
            parent[v] = u;
            rank[u]++;
        }
        else if(rank[u] != rank[v]) {
            if(rank[u]>rank[v]) {
                parent[v] = u;
            }
            else {
                parent[u] = v;
            }
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n,-1);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) {
            parents[i] = i;
        }
        for(auto edge:edges) {
            unionfind(edge,parents,rank);
        }
        unordered_set<int> uset;
        for(auto parent:parents) {
            uset.insert(find_parent(parent,parents));
        }
        return uset.size();
    }
};
