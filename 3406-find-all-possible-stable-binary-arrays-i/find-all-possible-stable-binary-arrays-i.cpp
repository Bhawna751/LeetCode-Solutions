class Solution {
public:
    int mod=1e9+7,t[201][201][2];
    int solve(int ones,int zeros,bool last,int limit){
        if(zeros==0&&ones==0)
        return 1;
        if(t[ones][zeros][last]!=-1)
        return t[ones][zeros][last];
        long long ans=0;
        if(last==1){
            for(int i=1;i<=min(zeros,limit);i++)
            ans=(ans+solve(ones,zeros-i,false,limit))%mod;
        }
        else{
            for(int i=1;i<=min(ones,limit);i++)
            ans=(ans+solve(ones-i,zeros,true,limit))%mod;
        }
        return t[ones][zeros][last]=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        return (solve(one,zero,false,limit)+solve(one,zero,true,limit))%mod;;
    }
};