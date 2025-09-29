class Solution {
public:
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-1; i>=0; i--){
            for(int j=i+2; j<n;j++){
                dp[i][j]=1e9;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j], 
                                dp[i][k] + values[i]*values[k]*values[j] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};