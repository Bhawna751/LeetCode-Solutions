#define mod 1000000007
#define ll long long int

class Solution {
public:
    int checkRecord(int n) {
        vector<vector<ll>> dp(3, vector<ll> (4));
        for(int a=0;a<=1;a++){
            for(int l=0;l<=2;l++){
                dp[a][l]=1;
            }
        }
        for(int day=1;day<=n;day++){
            vector<vector<ll>> next(3, vector<ll>(4));
            for(int a=0;a<=1;a++){
                for(int l=0;l<=2;l++){
                    next[a][l] = dp[a][0]%mod;
                    next[a][l] = (next[a][l] + dp[a+1][0])%mod;
                    next[a][l] = (next[a][l] + dp[a][l+1]) % mod;
                }
            }
            dp = next;
        }
        return dp[0][0];
    }
};