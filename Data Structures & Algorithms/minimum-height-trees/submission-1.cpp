class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> indegree(n, 0);
        queue<int> q;

        for(int i=0;i<n;i++) {
            indegree[i] = adj[i].size();
            if(indegree[i] == 1) q.push(i);
        }

        while(!q.empty()) {
            if (n <= 2) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front());
                    q.pop();
                }
                return result;
            }
            int len = q.size();

            for(int i=0;i<len;i++) {
                int curr = q.front();
                q.pop();
                n--;

                for(int nd:adj[curr]) {
                    indegree[nd]--;
                    if(indegree[nd] == 1) q.push(nd);
                }
            }
        }

        return {};
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