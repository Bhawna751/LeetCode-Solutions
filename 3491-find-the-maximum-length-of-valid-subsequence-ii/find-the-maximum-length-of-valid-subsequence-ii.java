class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;//1,4,2,3,1,4 k=3
        int[][] dp=new int[k][k];/*
        0  4  0  
        0  0  1 
        1  0  0  
        */
        int ans=0;//ans=0
        for(int it:nums){//it --> remainder
            it = it%k;//it = 1
            for(int i=0;i<k;i++){//--> length of subs ending at i
                dp[i][it] = dp[it][i] + 1;// 
                ans = Math.max(ans,dp[i][it]);//ans=4
            }
        }
        return ans;
    }
}