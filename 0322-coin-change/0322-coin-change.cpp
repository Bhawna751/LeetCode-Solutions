class Solution {
public:
    
    int solve(vector<int> &coins, int ind, int amount,vector<vector<int>> &dp){
        if(ind == coins.size() || amount <= 0) return amount == 0 ? 0:1e9;
        if(dp[ind][amount] != -1)return dp[ind][amount];
        int ans = -1;
        if(coins[ind] > amount){
            int notpick = solve(coins,ind+1,amount,dp);
            dp[ind][amount] = ans = notpick;
        }
        else{
            int pick = 1 + solve(coins,ind, amount - coins[ind],dp);// 1+_+1+_+1+_+1+_+1+_+1+0
            int notpick = solve(coins,ind+1,amount,dp);//
            dp[ind][amount] = ans = min(pick,notpick);
        }
        return dp[ind][amount] = ans;
    }
    // coins = 1,2,5 amount = 6
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1,-1)); 
        /*
            -1 -1 -1 -1 -1 -1 -1 
            -1 -1 -1 -1 -1 -1 -1 
            -1 -1 -1 -1 -1 -1 -1 
            -1 -1 -1 -1 -1 -1 -1 
        */
        int ans = solve(coins,0,amount,dp);
        return ans == 1e9 ? -1: ans;
    }
};