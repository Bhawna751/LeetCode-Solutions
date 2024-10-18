class Solution {
public:
    int cntSubsets(vector<int> &nums, int ind, int cur, int maxi,vector<vector<int>> &dp){
        if(ind == nums.size()) return (cur == maxi) ? 1:0;
        int notpick = cntSubsets(nums,ind+1, cur, maxi,dp);
        int pick = cntSubsets(nums,ind+1, cur|nums[ind], maxi,dp);
        return dp[ind][cur]=pick+notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, n= nums.size();
        for(int it:nums){
            maxi = max(maxi, it|maxi);
        }
        vector<vector<int>> dp(n, vector<int> (maxi+1));
        return cntSubsets(nums,0, 0, maxi,dp);
    }
};