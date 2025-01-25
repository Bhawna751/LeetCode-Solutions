class Solution {
public:
    void solve(vector<vector<string>>&ans, vector<string>&board, int j){
        if(j == board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(valid(board,i,j)){
                board[i][j] = 'Q';
                solve(ans,board,j+1);
                board[i][j]='.';
            }
        }
    }
    bool valid(vector<string>&board, int row, int col){
        int r=row, c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        while(c>=0){
            if(board[r][c]=='Q')return false;
            c--;
        }
        r=row;
        c=col;
        while(c>=0 && r<board.size()){
            if(board[r][c]=='Q')return false;
            r++;
            c--;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(ans,board,0);
        return ans;
    }
};