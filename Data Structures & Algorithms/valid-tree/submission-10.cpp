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

        return true;
    }

    bool canConnectedGraph() {
        int first_parent = findParent(0);
        for(int i=1;i<parent.size();i++) {
            int p = findParent(i);
            if(p != first_parent) return false;
        }
        return true;
    }
    friend class Solution;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false;

        DSU uf(n);
        for(int i=0;i<edges.size();i++) {
            if(!uf.union_find(edges[i][0], edges[i][1])) return false;
        }

        return uf.canConnectedGraph();
    }
};

