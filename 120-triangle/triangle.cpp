class Solution {
public:
    int solve(vector<vector<int>>&triangle,vector<vector<int>>&dp){
        int n= triangle.size();
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = dp[i+1][j]+triangle[i][j];
                int diag = dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(down, diag);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m=triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(triangle,dp);
    }
};