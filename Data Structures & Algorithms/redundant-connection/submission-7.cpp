class DSU {
    int n;
    vector<int> parent, rank;
    int find_parent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find_parent(parent[node]);
    }
public:
    DSU(int n) {
        this->n = n;
        for(int i=0;i<n;i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int Union_Find(int node1, int node2) {
        int u = find_parent(node1);
        int v = find_parent(node2);

        if(u == v) return false;
        else if(rank[u] == rank[v]) {
            rank[u] += 1;
            parent[v] = u;
        } else if(rank[u] > rank[v]) parent[v] = u;
        else parent[u] = v;

        return true;
    }
    friend class Solution;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        DSU dsu(n);
        for(int i=0;i<n;i++) {
            if(!dsu.Union_Find(edges[i][0], edges[i][1])) return edges[i];
        }
        return {};
    }
};