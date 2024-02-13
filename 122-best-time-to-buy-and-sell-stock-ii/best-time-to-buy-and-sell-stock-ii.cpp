class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<int>>& dp) {
        if (ind == n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                         0 + f(ind + 1, 1, prices, n, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp),
                         0 + f(ind + 1, 0, prices, n, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int b = 0; b <= 1; b++) {
                int profit = 0;
                if (b) {
                    profit = max(-prices[ind] + dp[ind + 1][0],dp[ind + 1][ 1]);
                } else {
                    profit = max(prices[ind] + dp[ind+1][1], dp[ind + 1][0]);
                }
                 dp[ind][b] = profit;
            }
        }
        return dp[0][1];
    }
};