class Solution {
    public int checkRecord(int n) {
        int mod = 1_000_000_007;
        int[][][] dp = new int[100001][3][4];
        for(int a=0;a<=1;a++){
            for(int l=0;l<=2;l++){
                dp[0][a][l]=1;
            }
        }
        for(int day=1;day<=n;day++){
            for(int a=0;a<=1;a++){
                for(int l=0;l<=2;l++){
                    dp[day][a][l] = dp[day-1][a][0]%mod;
                    dp[day][a][l] = (dp[day][a][l] + dp[day-1][a+1][0])%mod;
                    dp[day][a][l] = (dp[day][a][l] + dp[day-1][a][l+1]) % mod;
                }
            }    
        }
        return dp[n][0][0];
    }
}