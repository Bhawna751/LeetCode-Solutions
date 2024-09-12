class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        /*
        -1 -1 -1 -1 -1 -1 -1
        -1 -1 -1 -1 -1 -1 -1
        */
        return solve(nums,dp,0,-1);
    }
    int solve(vector<int> &nums, vector<vector<int>> &dp, int i, int prev){
        if( i>= nums.size()) return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int pick = 0;
        int notpick = solve(nums,dp,i+1, prev);
        if(prev == -1 || nums[i] > nums[prev]) pick = 1+solve(nums,dp,i+1,i);
        return dp[i][prev+1] = max(pick,notpick); 
    }
};