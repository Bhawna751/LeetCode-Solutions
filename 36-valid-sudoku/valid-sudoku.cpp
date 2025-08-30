class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis1[9][9] = {0},vis2[9][9] = {0},vis3[9][9] = {0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int it = board[i][j] - '0' -1;
                    int k = i/3 * 3+j /3;
                    if(vis1[i][it] || vis2[j][it] || vis3[k][it]) return false;
                    vis1[i][it] = 1;
                    vis2[j][it] = 1;
                    vis3[k][it] = 1;
                }
            }
        }
        return true;
    }
};