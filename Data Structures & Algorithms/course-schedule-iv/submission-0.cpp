class Solution {
public:
    unordered_map<int, unordered_set<int>> mp;
    unordered_set<int> dfs(int node, vector<vector<int>>& adj) {
        if(mp.count(node)) return mp[node];

        mp[node] = unordered_set<int>();
        for(int pre:adj[node]) {
            unordered_set<int> res = dfs(pre, adj);
            mp[node].insert(res.begin(), res.end());
        }
        mp[node].insert(node);
        return mp[node];
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++) {
            if(!mp.count(i)) unordered_set<int> curr = dfs(i, adj);
        }

        vector<bool> res;
        for(int i=0;i<queries.size();i++) {
            if(mp[queries[i][0]].count(queries[i][1])) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};