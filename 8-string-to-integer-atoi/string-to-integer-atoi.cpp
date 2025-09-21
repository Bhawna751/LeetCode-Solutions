class Solution {
public:
    int myAtoi(string s) {
        bool neg = 0; 
        int ans=0, i=0;
        while(s[i] == ' ')i++;
        if(s[i]=='-'){
            neg = 1;
            i++;
        } 
        else if(s[i]=='+'){
            neg=0;
            i++;
        }
        while(s[i] >= '0' && s[i]<='9'){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] - '0' > 7))
                return neg ? INT_MIN : INT_MAX;
            ans = (ans*10) + (s[i]-'0');
            i++;
        }
        return neg ? -ans:ans;
    }
};