class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        vector<int>cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = 1;
        }
        for(int ind = 1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int pick =0;
                if(coins[ind] <= target) pick = cur[target-coins[ind]];
                int notpick = prev[target];
                cur[target] = (long long)pick + (long long)notpick;
            }
            prev=cur;
        }
        return prev[amount];
    }
};