class Solution {
public:
    typedef tuple<int,int,int> T;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<T,vector<T>,greater<T>> pq;
        vector<vector<bool>> visit(m,vector<bool>(n,false));

        pq.push({grid[0][0],0,0});
        int res = 0;

        while(!pq.empty()) {
            int time = get<0>(pq.top());
            int u = get<1>(pq.top());
            int v = get<2>(pq.top());
            pq.pop();

            res = max(res,time);

            if(visit[u][v]) continue;
            if(u == m-1 && v == n-1) return res;

            visit[u][v] = true;

            for(auto [dr,dc]:dir) {
                int r = u+dr;
                int c = v+dc;

                if(r>=0 && c>=0 && r<m && c<n && !visit[r][c]) {
                    pq.push({max(grid[r][c],time),r,c});
                }
            }
        }
        return -1;
    }
};
