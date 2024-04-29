class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==grid.size()-1 && j<grid[0].size() && j>=0) return grid[i][j];
        if(j>=grid.size() || j<0) return 1e9;
        if(dp[i][j]!=1e9)return dp[i][j];
        int mini = 1e9;
        for(int k=0;k<grid[0].size();k++){
            if(k!=j){
                mini = min(mini,solve(i+1,k,grid,dp));
            }
        }
        return dp[i][j]=grid[i][j]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        int mini = 1e9;
        for(int i=0;i<n;i++){
            mini = min(mini,solve(0,i,grid,dp));
        }
        return mini;
    }
};