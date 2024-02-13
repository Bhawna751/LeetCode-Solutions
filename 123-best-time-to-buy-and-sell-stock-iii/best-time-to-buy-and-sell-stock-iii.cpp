class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {
        if (ind == n || cap == 0)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if (buy == 1) {
            return dp[ind][buy][cap] =
                       max(-prices[ind] + f(ind + 1, 0, cap, prices, n, dp),
                           f(ind + 1, 1, cap, prices, n, dp));
        }
        return max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp),
                   f(ind + 1, 0, cap, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                         dp[ind][buy][cap] =max(-prices[ind] +dp[ind + 1][0][cap],dp[ind + 1][1][cap]);
                    }
                    else{
                         dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap-1],dp[ind + 1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};