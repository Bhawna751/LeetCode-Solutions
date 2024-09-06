class Solution {
public:
    //memoization
    // int solve(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind<0)return 0;
    //     if(ind==0)return nums[0];
    //     if(dp[ind]!=-1)return dp[ind];

    //     int pick = nums[ind] + solve(ind-2,nums,dp);
    //     int notpick = solve(ind-1,nums,dp);
    //     dp[ind]=max(pick,notpick);
    //     return dp[ind];
    // }
    //TABULATION:
    // int solve(int n,vector<int>&nums,vector<int>&dp){
    //     dp[0] = nums[0];
    //     for(int i=1;i<n;i++){
    //         int pick = nums[i];
    //         if(i>1) pick+= dp[i-2];
    //         int notpick = dp[i-1];
    //         dp[i] = max(pick,notpick);
    //     }
    //     return dp[n-1];
    // }
    int solve(int n,vector<int>&nums){
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notpick = prev;
            int cur = max(pick,notpick);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(n,nums);
        return ans;
    }
};