class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int Size = flights.size();

        for(int i=0;i<Size;i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<vector<int>> qmin;
        qmin.push({0, src, k+1});
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        while(!qmin.empty()) {
            int cost = qmin.front()[0];
            int node = qmin.front()[1];
            int stops = qmin.front()[2];
            qmin.pop();

            if(dst == node) continue;
            if(stops == 0) continue;

            for(auto [n, c]:adj[node]) {
                if(prices[n] > cost + c) {
                    prices[n] = cost + c;
                    qmin.push({prices[n], n, stops-1});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

/*
adj = {
    0: [ {1, 5} {3, 2} ],
    1: [ {2, 5} {4, 1} ],
    3: [ {1, 2} ],
    4: [ {2, 1} ],
}
dst = 2
qmin = { [4, 1, 1] [5, 1, 2] [5, 4, ] [9, 2, 0] }
          ^

visited = [true, true, false, true, false]
*/