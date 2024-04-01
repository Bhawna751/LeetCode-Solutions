typedef long long ll;
class Solution {
public:
    int RabinKarp(string s1,string s2){
        ll n=s1.size(),m=s2.size(),p=31,pow=1,mod=1e9+7,target=0;
        for(ll i=0;i<m;i++){
            target = (target+(s2[i]-'a'+1)*pow)%mod;
            pow = (pow*p)%mod;
        }
        vector<ll> prefix(n),power(n);
        prefix[0]=s1[0]-'a'+1;
        power[0]=1;
        pow=p;
        for(ll i=1;i<n;i++){
            prefix[i]=(prefix[i-1] + (s1[i]-'a'+1)*pow)%mod;
            power[i]=pow;
            pow=(pow*p)%mod;
        }
        ll start=0,end=m-1;
        while(end<n){
            ll slider=prefix[end];
            if(start>0) slider=(slider-prefix[start-1]+mod)%mod;
            if(slider== (target*power[start])%mod)return 1;
            start++;end++;
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b)return 1;
        int cnt=1;string source=a;
        while(source.size()<b.size()){
            source+=a;cnt++;
        }
        if(source==b)return cnt;
        if(RabinKarp(source,b)==1)return cnt;
        if(RabinKarp(source+a,b)==1)return cnt+1;
        return -1;
    }
};