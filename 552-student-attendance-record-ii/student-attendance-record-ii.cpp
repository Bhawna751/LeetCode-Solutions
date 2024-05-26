#define mod 1000000007
#define ll long long int

class Solution {
public:
    ll dp[100001][3][3];
    ll solve(int n,int a,int l){
        if(n==0)return 1;
        if(dp[n][a][l]!=-1){
            return dp[n][a][l];
        }
        ll ans=0;
        ans= solve(n-1,a,0) % mod;
        if(a<1) ans = (ans + solve(n-1,a+1,0)) % mod;
        if(l<2) ans = (ans + solve(n-1,a,l+1))%mod;
        return dp[n][a][l]= ans % mod;
    }

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};