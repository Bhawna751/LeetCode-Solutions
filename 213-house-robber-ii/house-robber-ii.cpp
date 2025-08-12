class Solution {
public:
    int solve( vector<int> &arr){
        int ind = arr.size();
        vector<int> dp(ind,0);
        if(ind ==0)return arr[ind];
        if(ind<0)return 0;
        dp[0]=arr[0];
        for(int i=1;i<ind;i++){
            int pick = arr[i];
            if(i>1)pick += dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick ,notpick);
        }
        return dp[ind-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1, arr2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1)arr1.push_back(nums[i]);
            if(i!=0) arr2.push_back(nums[i]);

        }
        vector<int> dp1(n,-1), dp2(n,-1);
        int ans1 = solve(arr1);
        int ans2  = solve(arr2);
        return max(ans1, ans2);
    }
};