class Solution {
public:
    bool solve(vector<int>&nums,int target, int ind,vector<vector<int>>dp){
        if(target==0)return true;
        if(ind==0)return nums[ind]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notpick = solve(nums,target,ind-1,dp);
        bool pick = false;
        if(nums[ind]<=target)pick = solve(nums,target-nums[ind],ind-1,dp);
        return dp[ind][target]=pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2==1)return false;
        else{
            int target = sum/2;
            vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
            for(int i=0;i<n;i++){
                dp[i][0]=1;
            }
            if(nums[0]<=target) dp[0][nums[0]]=1;
            for(int i=1;i<n;i++){
                for(int j=1;j<=target;j++){
                    bool pick = false;
                    if(nums[i]<=j)pick = dp[i-1][j-nums[i]];
                    bool notpick = dp[i-1][j];
                    dp[i][j] = pick||notpick;
                }
            }
            return dp[n-1][target];
        }
    }
};