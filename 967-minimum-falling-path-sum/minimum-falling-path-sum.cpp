class Solution {
public:
    int solve(vector<vector<int>>&matrix,vector<vector<int>> &dp, int i, int j, int m){
        if(j>=m || j<0)return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int up = matrix[i][j] + solve(matrix,dp, i-1, j, m);
        int left = matrix[i][j] + solve(matrix,dp, i-1, j-1, m);
        int right = matrix[i][j] + solve(matrix,dp, i-1, j+1, m);
        return dp[i][j]=min(up, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans= 1e9;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int j=0;j<m;j++){
           dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j]+dp[i-1][j];
                int left = matrix[i][j];
                if(j-1 >= 0)left += dp[i-1][j-1];
                else left += 1e9;
                int right = matrix[i][j];
                if(j+1 < m) right += dp[i-1][j+1];
                else right += 1e9;
                dp[i][j] = min(up,min(left, right));
            }
        }
        for(int j=0;j<m;j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};