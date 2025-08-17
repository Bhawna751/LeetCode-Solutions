class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j,vector<vector<int>> &dp){
        
        if(i<0|| j<0 ) return 1e9;
        if(i== 0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int up = grid[i][j] + solve(grid, i-1, j,dp);
        int left = grid[i][j] + solve(grid,i, j-1,dp);
        
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1)); 
        return solve(grid, n-1, m-1,dp);
    }
};