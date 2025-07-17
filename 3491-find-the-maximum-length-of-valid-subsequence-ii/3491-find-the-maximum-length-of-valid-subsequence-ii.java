class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] dp=new int[k][k];
        int ans=0;
        for(int it:nums){
            it = it%k;
            for(int i=0;i<k;i++){
                dp[i][it] = dp[it][i] + 1;
                ans = Math.max(ans,dp[i][it]);
            }
        }
        return ans;
    }
}