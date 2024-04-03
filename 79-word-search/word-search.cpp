class Solution {
public:
    bool search(vector<vector<char>>& board, string word,int row,int col,int ind,int n,int m){
        if(ind==word.length())return true;
        if(row<0 || col<0 || row==n || col==m || board[row][col]!=word[ind] or board[row][col]=='!')return false;
        char it=board[row][col];
        board[row][col]='!';
        bool top=search(board,word,row-1,col,ind+1,n,m);
        bool right=search(board,word,row,col+1,ind+1,n,m);
        bool left=search(board,word,row,col-1,ind+1,n,m);
        bool bottom=search(board,word,row+1,col,ind+1,n,m);
        board[row][col]=it;
        return top||right||left||bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int ind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[ind]){
                    if(search(board,word,i,j,ind,n,m))return true;
                }
            }
        }
        return false;
    }
};