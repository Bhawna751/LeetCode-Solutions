class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long unsigned> dp(amount + 1, 0);
        dp[0] = 1;

        for(auto num: coins) {

            for(int target = num; target <= amount; target++) {
                dp[target] += dp[target - num];
            }
        }
        return (int)dp[amount];
    }
};