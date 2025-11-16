class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        long long mod = 1e9+7;
        long long ans=0, cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                cnt = (cnt+1) % mod;
            }
            else cnt=0;
            ans = (ans+cnt) % mod;
        }
        return ans % mod;
    }
};