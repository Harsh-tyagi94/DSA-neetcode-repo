class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_set<string> uset;

        for (int i = 0; i < equations.size(); i++) {
            uset.insert(equations[i][0]);
            uset.insert(equations[i][1]);
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> res;

        for (auto query : queries) {
            string char1 = query[0], char2 = query[1];
            if (!uset.count(char1) || !uset.count(char2)) {
                res.push_back(-1.0);
                continue;
            }

            queue<pair<string, double>> q;
            double ans = -1.0;
            q.push({char1, 1.0});
            unordered_set<string> visited;

            while (!q.empty()) {
                auto [curr, cost] = q.front();
                q.pop();

                if (curr == char2) {
                    ans = cost;
                    break;
                }
                if (visited.count(curr)) continue;
                visited.insert(curr);

                for (auto& [neighbor, weight] : adj[curr]) {
                    if (!visited.count(neighbor))
                        q.push({neighbor, cost * weight});
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};