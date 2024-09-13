class Solution {
public:
    int solve(int amount, vector<int>& coins, int i,vector<vector<int>> &dp){
        if(i==0) return (amount % coins[i] == 0);
        if(dp[i][amount]!=-1)return dp[i][amount];
        int notpick = solve(amount,coins,i-1,dp);
        int pick = 0;
        if(coins[i]<= amount)pick= solve(amount - coins[i], coins, i,dp);
        return dp[i][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,n-1,dp);
    }
};