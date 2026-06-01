class Solution {
public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> qmin;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        qmin.push({grid[0][0], 0, 0});
        while(!qmin.empty()) {
            int cost = qmin.top()[0], r = qmin.top()[1], c = qmin.top()[2];
            qmin.pop();

            if(r == m-1 && c == n-1) return cost;
            if(visited[r][c]) continue;

            visited[r][c] = true;
            for(auto [dr, dc]:dir) {
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >=0 && nr < m && nc < n && !visited[nr][nc]) qmin.push({max(cost, grid[nr][nc]), nr, nc});
            }
        }
        return -1;
    }
};