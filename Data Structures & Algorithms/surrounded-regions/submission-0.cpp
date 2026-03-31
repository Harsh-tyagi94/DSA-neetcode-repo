class Solution {
private:
    void helper(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] || board[i][j]!='O'){
            return;
        }
        visited[i][j]=true;
    
        //up call,left,down,right calls:
        helper(board,visited,i-1,j);
        helper(board,visited,i,j-1);
        helper(board,visited,i+1,j);
        helper(board,visited,i,j+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1)){
                    helper(board,visited,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!visited[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};