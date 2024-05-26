#define mod 1000000007
#define ll long long int

class Solution {
public:
    ll dp[100001][3][4];
    int checkRecord(int n) {
        memset(dp,0,sizeof(dp));
        for(int a=0;a<=1;a++){
            for(int l=0;l<=2;l++){
                dp[0][a][l]=1;
            }
        }
        for(int day=1;day<=n;day++){
            for(int a=0;a<=1;a++){
                for(int l=0;l<=2;l++){
                    dp[day][a][l] = dp[day-1][a][0];
                    dp[day][a][l] = (dp[day][a][l] + dp[day-1][a+1][0])%mod;
                    dp[day][a][l] = (dp[day][a][l] + dp[day-1][a][l+1]) % mod;
                }
            }    
        }
        return dp[n][0][0];
    }
};