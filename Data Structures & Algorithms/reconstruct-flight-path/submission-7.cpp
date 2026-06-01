class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(int i=0;i<tickets.size();i++) {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for(auto i=adj.begin();i!=adj.end();i++) {
            string k = i->first;
            sort(adj[k].rbegin(), adj[k].rend());
        }

        vector<string> res;
        vector<string> Stack;
        Stack.push_back("JFK");
        while(!Stack.empty()) {
            string k = Stack.back();
            if(adj[k].size() != 0) {
                string new_addon = adj[k].back();
                adj[k].pop_back();
                Stack.push_back(new_addon);
            } else {
                res.push_back(Stack.back());
                Stack.pop_back();
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};