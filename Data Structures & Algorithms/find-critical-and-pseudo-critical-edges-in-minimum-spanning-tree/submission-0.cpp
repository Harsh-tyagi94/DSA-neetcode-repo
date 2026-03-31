class UnionFind {
public:
    vector<int> par, rank;

    UnionFind(int n) : par(n), rank(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if (v != par[v]) {
            par[v] = find(par[v]);
        }
        return par[v];
    }

    bool unionSets(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adj;
        for(int i=0;i<m;i++) {
            int u = edges[i][0], v = edges[i][1];
            adj.push_back({u,v,edges[i][2],i});
        }

        sort(adj.begin(), adj.end(), [](auto& a,auto& b) { 
            return a[2] < b[2];
        });

        int mstweight = 0;
        UnionFind uf(n);
        for(auto edge:adj) {
            if(uf.unionSets(edge[0],edge[1])) mstweight += edge[2];
        }

        vector<int> critical, pseudo;
        for(auto edge:adj) {
            
            int weight = 0;
            UnionFind ufwithout_edge(n);
            for(auto edgelist:adj) {
                if(edge[3] != edgelist[3] && 
                ufwithout_edge.unionSets(edgelist[0],edgelist[1])) weight += edgelist[2];
            }

            if(weight > mstweight || *max_element(ufwithout_edge.rank.begin(), ufwithout_edge.rank.end()) != n){
                critical.push_back(edge[3]);
                continue;
            }

            weight = edge[2];
            UnionFind ufwith_edge(n);
            ufwith_edge.unionSets(edge[0],edge[1]);
            for(auto edgelist:adj) {
                if(ufwith_edge.unionSets(edgelist[0],edgelist[1])) weight += edgelist[2];
            }

            if(mstweight == weight) pseudo.push_back(edge[3]);
        }
        return {critical, pseudo};
    }
};