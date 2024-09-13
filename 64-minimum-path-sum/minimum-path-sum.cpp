class Solution {
public:
    // Memeoization:
    //  int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&
    //  dp){
    //      if(i==0 && j==0)return grid[i][j];
    //      if(i<0 || j<0) return 1e9;
    //      if(dp[i][j]!=-1)return dp[i][j];
    //      int up = grid[i][j] + solve(i-1,j,grid,dp);
    //      int left = grid[i][j] + solve(i,j-1,grid,dp);
    //      return dp[i][j] = min(up,left);
    //  }
//TABULATION:
   
//Space optimized:
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size(), m=grid[0].size();
    //     vector<int> prev(m,0);
    //     for(int i=0;i<n;i++){
    //         vector<int> temp(m,0);
    //         for(int j=0;j<m;j++){
    //             if(i==0 && j==0) temp[j] = grid[i][j];
    //             else{
    //                 int up = grid[i][j];
    //                 if(i>0) up += prev[j];
    //                 else up += 1e9;
    //                 int left = grid[i][j];
    //                 if(j>0) left += temp[j-1];
    //                 else left += 1e9;
    //                 temp[j] = min(up,left);
    //             }
    //         }
    //         prev = temp;
    //     }
    //     return prev[m-1];
    // }
int minPathSum(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp (n, vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i = 1;i<n;i++) dp[i][0] = grid[i][0] + dp[i-1][0];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};