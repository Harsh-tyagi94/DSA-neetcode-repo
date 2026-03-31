class Solution {
public:
    int findHeight(vector<vector<int>>& adj, int node) {
        int h = 0;
        unordered_set<int> visited;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int len = q.size();

            for(int i=0;i<len;i++) {
                int curr = q.front();
                q.pop();

                visited.insert(curr);

                for(int nd:adj[curr]) {
                    if(!visited.count(nd)) q.push(nd);
                }
            }

            h += 1;
        }

        return h;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> res;
        int height = INT_MAX;
        for(int node=0;node<n;node++) {
            int h = findHeight(adj, node);
            if(height > h) {
                res = {node};
                height = h;
            } else if(height == h) {
                res.push_back(node);
            }
        }

        return res;
    }
};

/*
n = 4
edges = [[1,0],[1,2],[1,3]]
         ^

adj = {
    1: [0, 2, 3]
    0: [1]
    2: [1]
    3: [1]
}

node = 0
q = []
len = 2
curr = 3
visited = [0, 1, 2, 3]

*/