class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ans,int r,int c) {
                ans[r][c] = true;
                for(auto [dr,dc] : dir) {
                    int rn = r+dr;
                    int cn = c+dc;
                    if(rn>=0 && rn<m && cn>=0 && cn<n && 
                    !ans[rn][cn] && heights[rn][cn] >= heights[r][c]) {
                        dfs(heights,ans,rn,cn);
                    }
                }
                return;
            }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));

        for(int c=0;c<n;c++) {
            dfs(heights,pac,0,c);
            dfs(heights,atl,m-1,c);
        }
        for(int r=0;r<m;r++) {
            dfs(heights,pac,r,0);
            dfs(heights,atl,r,n-1);
        }
        vector<vector<int>> res;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
