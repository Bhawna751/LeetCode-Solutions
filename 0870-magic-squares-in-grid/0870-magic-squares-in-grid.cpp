class Solution {
public:
    bool magic(vector<vector<int>> &grid, int row, int col){
        bool vis[10] = {false};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int it = grid[row + i][col + j];
                if(it < 1 || it > 9)return false;
                if(vis[it])return false;
                vis[it]=true;
            }
        }
        int diag = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row + 2][col] + grid[row+1][col+1] + grid[row][col+2];
        if(diag != diag2) return false;
        int r1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int r2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row+1][col+2];
        int r3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row+2][col+2];
        if(!(r1 == diag && r2 == diag && r3 == diag)) return false;
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];
        if(!(col1 == diag && col2 == diag && col3 == diag)) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0, n=grid.size(), m=grid[0].size();
        for(int i=0;i+2 < n;i++){
            for(int j=0;j+2<m;j++){
                if(magic(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};