class Solution {
public:
vector<vector<vector<int>>> dp;
    int m, n;
    int f(int i,int j,int k,vector<vector<int>>& coins){
     
      
        if(i>=m||j>=n) return INT_MIN;
        if(i==m-1&&j==n-1){
            if(coins[i][j]<0&&k>0) return 0;
            return coins[i][j];
        }
        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
        int ans=INT_MIN;
        int right=f(i,j+1,k,coins);
        int down=f(i+1,j,k,coins);
        int best=max(right,down);
        if (best != INT_MIN) {
            ans = max(ans, coins[i][j] + best);
        }
        if(coins[i][j]<0&&k>0){
            int right2=f(i,j+1,k-1,coins);
            int down2=f(i+1,j,k-1,coins);
            int best2=max(right2,down2);
            if(best2!=INT_MIN){
                ans=max(ans,best2);
            }
        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
      m = coins.size();
      n = coins[0].size();  
        dp=vector<vector<vector<int>>>(m,(vector<vector<int>>(n,(vector<int>(3,INT_MIN)))));
         return f(0, 0, 2,coins);
    }
};