class Solution {
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    void connect_zero_region(vector<vector<char>>& board, int r, int c, int row, int col) {
        if(board[r][c] != 'O') return;

        board[r][c] = 'Y';
        for(auto [dr,dc]:dir) {
            int nr = r+dr;
            int nc = c+dc;
            if(nr>=0 && nr<row && nc>=0 && nc<col && board[nr][nc] == 'O') {
                connect_zero_region(board, nr, nc, row, col);
            }
        }
    } 
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();

        for(int c=0;c<col;c++) {
            connect_zero_region(board, 0, c, row, col);
            connect_zero_region(board, row-1, c, row, col);
        }
        for(int r=0;r<row;r++) {
            connect_zero_region(board, r, 0, row, col);
            connect_zero_region(board, r, col-1, row, col);
        }

        for(int r=0;r<row;r++) {
            for(int c=0;c<col;c++) {
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == 'Y') board[r][c] = 'O';
            }
        }

        return;
    }
};