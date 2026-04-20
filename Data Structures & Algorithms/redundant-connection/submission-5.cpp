class DSU {
    vector<int> parent;
    vector<int> rank;
    int findParent(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }
public:
    DSU (int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    bool union_find(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(parent_u == parent_v) return true;
        if(rank[parent_u] == rank[parent_v]) {
            rank[parent_u] += 1;
            parent[parent_v] = parent_u;
        } else if(rank[parent_u] > rank[parent_v]) parent[parent_v] = parent_u;
        else parent[parent_u] = parent_v;

        return false;
    }

    friend class Solution;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto edge:edges) {
            if(dsu.union_find(edge[0]-1,edge[1]-1)) {
                return edge;
            }
        }

        return {-1,-1};
    }
};
