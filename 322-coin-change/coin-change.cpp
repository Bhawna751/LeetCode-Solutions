class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int ind = 1;ind <n;ind++){
            for(int target = 0;target<=amount;target++){
                int pick = 1e9;
                if(target >= coins[ind])pick = 1 + dp[ind][target-coins[ind]];
                int notpick = dp[ind-1][target];
                dp[ind][target] = min(pick,notpick);
            }
        }
        int ans = dp[n-1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};