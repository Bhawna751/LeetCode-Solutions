class Solution {
public:
    int solve(vector<int>&nums, int n, int ind, int prev,vector<vector<int>> &dp){
        if(ind == n)return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int notpick = solve(nums,n,ind+1,prev,dp);
        int pick = 0;
        if(prev == -1 || nums[ind]>nums[prev]) pick = 1 + solve(nums,n,ind+1,ind,dp);
        return dp[ind][prev+1] = max(notpick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,n,0,-1,dp);
    }
};