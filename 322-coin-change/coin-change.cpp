class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),cur(amount +1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int ind = 1;ind <n;ind++){
            for(int target = 0;target<=amount;target++){
                int pick = 1e9;
                if(target >= coins[ind])pick = 1 + cur[target-coins[ind]];
                int notpick = prev[target];
                cur[target] = min(pick,notpick);
            }
            prev=cur;
        }
        int ans = prev[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};