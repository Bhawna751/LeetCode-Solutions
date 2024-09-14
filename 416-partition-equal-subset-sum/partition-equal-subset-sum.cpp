class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int total=0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total%2!=0)return false;
        else{
            int k = total/2;
            vector<vector<bool>> dp(n,vector<bool>(k+1,false));
            for(int i=0;i<n;i++) dp[i][0]=true;
            if(nums[0] <= k)dp[0][nums[0]] = true;
            for(int i=1;i<n;i++){
                for(int j=1;j<=k;j++){
                    bool notpick = dp[i-1][j];
                    bool pick = false;
                    if(nums[i] <= j) pick = dp[i-1][j-nums[i]];
                    dp[i][j] = notpick || pick;
                }
            }
            return dp[n-1][k];
        }
    }
};