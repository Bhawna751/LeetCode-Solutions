const int MOD = 1000000007;
class Solution {
public:
    long long modInverse(long long x, long long mod){
        return exponent(x,mod-2,mod);
    }
    long long nCr(int n, int r, vector<long long>&fact){
        return fact[n] * modInverse(fact[r], MOD) % MOD * modInverse(fact[n-r], MOD) % MOD;
    }
    long long exponent(long long base, long long exp, long long mod){
        long long ans=1;
        while(exp>0){
            if(exp % 2 == 1) ans = (ans * base) % mod;
            base = (base * base) %mod;
            exp = exp/2;
        }
        return ans;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i] = fact[i-1] * i % MOD;
        }
        long long ans = nCr(n-1,k,fact);
        ans = ans * m % MOD;
        ans = ans * exponent(m-1,n-1-k,MOD) % MOD;
        return ans;
    }
};