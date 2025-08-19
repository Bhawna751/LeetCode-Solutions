class Solution {
public:
    int solve(vector<int>& coins , int amount  , int i ,vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(i >= coins.size() || amount < 0)  return 0;
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = solve(coins , amount - coins[i] , i , dp );
        int skip = solve(coins , amount , i +1 , dp);
        dp[i][amount] = take + skip;
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        int index = 0;
        int ans = solve(coins , amount , index , dp);
        return ans;
    }
};