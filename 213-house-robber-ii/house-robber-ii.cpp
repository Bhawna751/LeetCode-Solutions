class Solution {
public:
    int solve(vector<int>&arr, int ind,vector<int>&dp){
        if(ind ==0)return arr[ind];
        if(ind < 0)return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = solve(arr, ind-2,dp)+arr[ind];
        int notpick = solve(arr, ind-1,dp);
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>arr1, arr2;
        int n = nums.size();
        vector<int>dp1(n,-1), dp2(n,-1);
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1)arr1.push_back(nums[i]);
            if(i!=0) arr2.push_back(nums[i]);
        }
        int ans1 = solve(arr1, arr1.size()-1,dp1);
        int ans2 = solve(arr2, arr2.size()-1,dp2);
        return max(ans1,ans2);
    }
};