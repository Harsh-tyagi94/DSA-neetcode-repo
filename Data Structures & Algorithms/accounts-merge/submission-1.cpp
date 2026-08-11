class DSU {
    vector<int> parent;
    vector<int> rank;
    int find_parent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = find_parent(parent[node]);
    }
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    void UnionFind(int n1, int n2) {
        int u = find_parent(n1);
        int v = find_parent(n2);

        if(u == v) return;
        else if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else {
            rank[u] += 1;
            parent[v] = u;
        }
        return;
    }
    void BuildParentToChildRelation(unordered_map<int, vector<int>> &ump) {
        for(int i=0;i<parent.size();i++) {
            int root = find_parent(i);
            ump[root].push_back(i);
        }
        return;
    }

    friend class Solution;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailName;
        for(int i=0;i<n;i++) {
            int sz = accounts[i].size();
            for(int j=1;j<sz;j++) {
                string acc = accounts[i][j];
                if(emailName.count(acc)) {
                    dsu.UnionFind(emailName[acc], i);
                } else emailName[acc] = i;
            }
        }

        unordered_map<int, vector<int>> ump;
        dsu.BuildParentToChildRelation(ump);
        vector<vector<string>> res;
        for(auto it=ump.begin();it!=ump.end();it++) {
            int k = it->first;
            set<string> st;
            for(int i : ump[k]) {
                for(int j=1;j<accounts[i].size();j++) st.insert(accounts[i][j]);
            }
            vector<string> ans;
            ans.push_back(accounts[k][0]);
            while(st.size()>0) {
                ans.push_back(*st.begin());
                st.erase(ans.back());
            }
            res.push_back(ans);
        }
        return res;
    }
};