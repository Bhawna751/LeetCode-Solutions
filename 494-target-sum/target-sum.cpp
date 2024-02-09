class Solution {
public:
    
    int findways(vector<int> &nums, int s1){
        int n = nums.size();
        int dp[n+1][s1+1];
        dp[0][0]=1;
        
        for(int ind=1;ind<s1+1;ind++){
            dp[0][ind]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s1+1;j++){
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            } 
        }
        return dp[n][s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(abs(target)>sum || (sum-target)%2!=0){
            return 0;
        }
        int s1 = (sum + target)/2;
        int ans = findways(nums,s1);
        return ans;
    }
};