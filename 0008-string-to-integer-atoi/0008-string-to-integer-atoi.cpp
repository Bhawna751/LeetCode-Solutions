class Solution {
public:
    long long solve(string s,int sign,int i,long long res){
        if(sign*res>=INT_MAX)return INT_MAX;
        if(sign*res<=INT_MIN)return INT_MIN;
        if(s[i]==' '||!isdigit(s[i]))return res*sign;
        int sol = s[i]-'0';
        return solve(s,sign,i+1,res*10+sol);
    }
    int myAtoi(string s) {
        int flag=0,i=0,n=s.size(),sign=1;
        
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-'){
            sign=-1;
            i++;flag++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;flag++;
        }
        if(flag>1)return 0;
        return solve(s,sign,i,0);
    }
};