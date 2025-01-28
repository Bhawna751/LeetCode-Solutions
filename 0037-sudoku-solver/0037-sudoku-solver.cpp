class Solution {
public:
    bool valid(vector<vector<char>>&board, int r, int c, int d){
        for(int i=0;i<9;i++) {
            if(board[r][i]==d || board[i][c]==d)return false;
        }
        int sc = (c/3)*3, sr = (r/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j] == d)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char d = '1' ; d<='9';d++){
                        if(valid(board,i,j,d)){
                            board[i][j]=d;
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};