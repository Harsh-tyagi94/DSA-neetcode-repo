class Solution {
private:
    bool helper(vector<vector<char>>& board, string word,int i,int j,int idx,int m,int n){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }
        if(idx==word.length()-1){
            return true;
        }
        board[i][j]='*';
        //left right up down
        if(helper(board,word,i,j-1,idx+1,m,n) || helper(board,word,i,j+1,idx+1,m,n)
                || helper(board,word,i-1,j,idx+1,m,n) || helper(board,word,i+1,j,idx+1,m,n)){
                    return true;
                }
        board[i][j]=word[idx];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size(); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                   if(helper(board,word,i,j,0,m,n))
                   return true;
                }
            }
        }
        return false;
    }
};
