class Solution {
public:
    int helper(vector<int> &nums, int s1){
        int n=nums.size();//n = 10
        int dp[n+1][s1+1];
        dp[0][0]=1;

        for(int i=1;i<s1+1;i++) dp[0][i]=0;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        // [12,25,42,49,41,15,22,34,28,31]
        //35
        for(int i=0;i<nums.size();i++) sum+= nums[i];//sum = 299
        if(abs(target) >  sum || (sum-target)%2 != 0) return 0;  
        int s1=(sum + target)/2;//s1 = 167
        return helper(nums,s1); 
    }
};