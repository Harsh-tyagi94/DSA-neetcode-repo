class UnionFind {
private: 
    int size;
    vector<int> parent;
    vector<int> rank;
    
    void disjoint_set(vector<int>& parent, vector<int>& rank) {
        for(int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find_parent(int node, vector<int>& parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = find_parent(parent[node], parent);
    }
    
public:
    UnionFind(int V) {
        this->size = V;
        parent.resize(size);
        rank.resize(size);
        disjoint_set(parent, rank);
    }
    
    void unite(int node1, int node2) {
        int u = find_parent(node1, parent);
        int v = find_parent(node2, parent);

        if(u == v) {
            return;
        }
        
        if(rank[u] == rank[v]) {
            parent[v] = u;
            rank[u]++;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u; 
        }
        else {
            parent[u] = v;
        }
    }

    int connected_check() {
        unordered_set<int> uset;
        for(auto i:parent) {
            i = find_parent(i,parent);
            if(uset.find(i) == uset.end()) {
                uset.insert(i);
            }
        }
        return uset.size();
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto edge:edges) {
            uf.unite(edge[0],edge[1]);
        }
        return uf.connected_check();
    }
};
