typedef long long ll;
class Solution {
public:
    ll solve(string s,ll ans,int sign,int i){
        if(sign*ans>=INT_MAX)return INT_MAX;
        else if(sign*ans<=INT_MIN)return INT_MIN;
        else if(s[i]==' '|| !isdigit(s[i])) return ans*sign;
        int res=s[i]-'0';
        return solve(s,ans*10+res,sign,i+1);
    }
    int myAtoi(string s) {
        int flag=0,i=0,n=s.size(),sign=1;
        while(i<n && s[i]==' ')i++;
        if(s[i]=='-'){
            sign= -1;
            i++;
            flag++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;flag++;
        }
        if(flag>1)return 0;
        return solve(s,0,sign,i);
    }
};