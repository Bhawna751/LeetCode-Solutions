class Solution {
public:
    void solve(vector<string>&board, vector<vector<string>>&ans,int j){
        if(j == board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(valid(board,i,j)){
                board[i][j] = 'Q';
                solve(board,ans,j+1);
                board[i][j] = '.';
            }
        }
    }
    bool valid(vector<string>&board, int i, int j){
        int r = i, c=j;
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q')return false;
            r--;
            c--;
        }
        r=i;
        c=j;
        while(c>=0){
            if(board[r][c] == 'Q')return false;
            c--;
        }
        r=i;
        c=j;
        while(c>=0 && r<board.size()){
            if(board[r][c] == 'Q')return false;
            r++;
            c--;
        }
        return true;
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(board,ans,0);
        return ans;
    }
};