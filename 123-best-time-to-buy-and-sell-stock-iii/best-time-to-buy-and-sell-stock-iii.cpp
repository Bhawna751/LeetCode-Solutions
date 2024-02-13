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
        vector<vector<int>>after(2, vector<int>(3,0));
        vector<vector<int>>cur(2, vector<int>(3,0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                         cur[buy][cap] =max(-prices[ind] +after[0][cap],after[1][cap]);
                    }
                    else{
                         cur[buy][cap] = max(prices[ind] + after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after=cur;
        }
        return cur[1][2];
    }
};