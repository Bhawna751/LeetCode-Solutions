class Solution {
public:
    bool solve(vector<int> &nums, int k, int i,vector<vector<int>> &dp){
        if(k==0)return true;
        if(i==0)return nums[i] == k;
        if(dp[i][k] !=-1) return dp[i][k];
        bool notpick = solve(nums,k,i-1,dp);
        bool pick = 0;
        if(nums[i] <= k) pick = solve(nums,k-nums[i],i-1,dp);
        return dp[i][k]= notpick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int total=0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        if(total%2!=0)return false;
        else{
            int k = total/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return solve(nums,k,n-1,dp);
        }
    }
};