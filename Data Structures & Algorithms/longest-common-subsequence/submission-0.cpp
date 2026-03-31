class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row=text2.length(),col=text1.length();
        vector<vector<int>> vec(row+1,vector<int>(col+1));
        for(int i=0;i<=col;i++){
            vec[0][i]=0;
        }
        for(int i=0;i<=row;i++){
            vec[i][0]=0;
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(text1[j-1]==text2[i-1]){
                    vec[i][j]=1+vec[i-1][j-1];
                }
                else{
                    vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }
        return vec[row][col];
    }
};
