class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;col--;
        }
        col=dupcol; row=duprow;
        while (col >= 0) {
        if (board[row][col] == 'Q')
            return false;
        col--;
        }
        col=dupcol; row=duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;col--;
        }
        return true;
    }
    void solve(int ind,vector<string> &board,vector<vector<string>> &ans,int n){
        if(ind==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,ind,board,n)){
                board[i][ind]='Q';
                solve(ind+1,board,ans,n);
                board[i][ind]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};