class Solution {
public:
    vector<int> MatrixBuild(int k, vector<vector<int>>& Conditions) {
        vector<int> indegree(k+1, 0);
        vector<int> res(k+1, 0);
        vector<vector<int>> adj(k+1);
        
        for(int i=0;i<Conditions.size();i++) {
            int u = Conditions[i][0], v = Conditions[i][1];
            indegree[u] += 1;
            adj[v].push_back(u);
        }

        queue<int> Queue;
        for(int i=1;i<=k;i++) {
            if(indegree[i] == 0) Queue.push(i);
        }

        
        while(!Queue.empty()) {
            int node = Queue.front();
            Queue.pop();

            res[node] = k-1;
            k -= 1;

            for(int neigh:adj[node]) {
                if(indegree[neigh] == 1) Queue.push(neigh);
                indegree[neigh] -= 1;
            }
        }
        if(k != 0) return {};
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<int> Roworder = MatrixBuild(k, rowConditions);
        vector<int> Colorder = MatrixBuild(k, colConditions);

        if(Roworder.empty() || Colorder.empty()) return {};
        for(int i=1;i<=k;i++) {
            res[Roworder[i]][Colorder[i]] = i;
        }
        return res;
    }
};