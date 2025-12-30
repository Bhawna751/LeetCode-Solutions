class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j)
    {
        vector<int> vis(10, 0);
        for(int r=i; r<i+3; r++)
        {
            for(int c=j; c<j+3; c++)
            {
                int x = grid[r][c];
                if(x < 1 || x > 9) return false;
                if(vis[x]) return false;
                vis[x] = 1;
            }
        }

           int rowSum1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
           int rowSum2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
           int rowSum3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

           if(rowSum1 != rowSum2 || rowSum2 != rowSum3) return false;
           
           int colSum1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
           int colSum2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
           int colSum3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

           if(colSum1 != colSum2 || colSum2 != colSum3) return false;

           int dia1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
           int dia2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];

           if(dia1 != dia2) return false;

           if(rowSum1 != colSum1 || rowSum1 != colSum2 || rowSum1 != colSum3 || rowSum1 != dia1) return false;

           return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                if(check(grid, i, j))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};