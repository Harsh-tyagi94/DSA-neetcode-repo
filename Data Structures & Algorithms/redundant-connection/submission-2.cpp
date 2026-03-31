class DSU {
private:
    int size;
    vector<int> parent;
    vector<int> rank;

    void DisjointSet() {
        for(int i=0;i<=size;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        return;
    }

    int FindParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = FindParent(parent[node]);
    }
public:
    DSU(int s) {
        this->size = s;
        parent.resize(size+1);
        rank.resize(size+1);
        DisjointSet();
    }

    bool Union(int n1,int n2) {
        int u = FindParent(n1);
        int v = FindParent(n2);

        if(u == v) {
            return false;
        }

        if(rank[u] == rank[v]) {
            parent[v] = u;
            rank[u]++;
        } else if(rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[u] = v;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto edge:edges) {
            if(!dsu.Union(edge[0],edge[1])) {
                return edge;
            }
        }

        return {-1,-1};
    }
};
