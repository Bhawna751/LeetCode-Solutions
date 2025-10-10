class Solution {
public:
    int solve(vector<int>&coins, int ind, int target,vector<vector<int>>&dp){
        if(ind==0){
            if(target % coins[ind] == 0) return target / coins[ind];
            return 1e9;   
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int pick = 1e9;
        if(coins[ind]<=target) pick = 1 + solve(coins, ind, target-coins[ind],dp); 
        int notpick = solve(coins, ind-1, target,dp);
        return dp[ind][target]=min(pick ,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins, n-1, amount,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};