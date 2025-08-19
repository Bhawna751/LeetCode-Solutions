class Solution {
public:
    const int MOD = 1e9+7;
    int solve(vector<int> &nums, int target, int ind, vector<vector<int>>&dp){
        if(ind ==0){
            if(target == 0  && nums[ind]==0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        int notpick = solve(nums, target, ind-1,dp);
        int pick=0;
        if(nums[ind]<=target) pick = solve(nums, target-nums[ind], ind-1,dp);
        return dp[ind][target] = (pick+notpick) %MOD;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total-target < 0 || (total-target)%2==1)return 0;
        int k = (total - target)/2;
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        return solve(nums, k, n-1,dp);

    }
};