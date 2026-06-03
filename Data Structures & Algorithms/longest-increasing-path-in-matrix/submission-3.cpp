class Solution {
public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                for(auto [dr, dc]:dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nc >=0 && nr < m && nc < n && matrix[nr][nc] < matrix[r][c]) 
                        indegree[r][c] += 1;   
                }
            }
        }

        queue<vector<int>> q;
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(indegree[r][c] == 0) q.push({r, c});
            }
        }

        int res = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                int r = q.front()[0], c = q.front()[1];
                q.pop();

                for(auto [dr, dc]:dir) {
                    int nr = r + dr, nc = c + dc;
                    if(nr >= 0 && nc >=0 && nr < m && nc < n && matrix[nr][nc] > matrix[r][c]) {
                        if(--indegree[nr][nc] == 0) q.push({nr, nc});
                    }
                }
            }
            res += 1;
        }
        return res;
    }
};