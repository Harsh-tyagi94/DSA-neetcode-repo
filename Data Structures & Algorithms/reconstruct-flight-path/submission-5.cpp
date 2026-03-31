class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> ump;

        for(auto ticket:tickets) {
            ump[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [src, destinations] : ump) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> res;
        stack<string> stk;
        stk.push("JFK");

        while (!stk.empty()) {
            string curr = stk.top();
            if (ump[curr].empty()) {
                res.push_back(curr);
                stk.pop();
            } else {
                string next = ump[curr].back();
                ump[curr].pop_back();
                stk.push(next);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
