class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = 1;
        }
        for(int ind = 1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int pick =0;
                if(coins[ind] <= target) pick = dp[ind][target-coins[ind]];
                int notpick = dp[ind-1][target];
                dp[ind][target] =(long long)pick + (long long)notpick;
            }
        }
        return dp[n-1][amount];
    }
};