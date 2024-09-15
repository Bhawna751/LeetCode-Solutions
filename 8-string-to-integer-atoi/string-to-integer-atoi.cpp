class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, base = 0, i=0;
        while(s[i] == ' ') i++;//increment for leading whitespaces
        if(s[i]=='-' || s[i]=='+') sign = 1-2*(s[i++]=='-');//check for sign and assign flag value accordingly
        while(s[i] >= '0' && s[i] <= '9'){//till it's a digit b/w 0-9...
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i] - '0' > 7)){//check the overflow condition
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base = 10 * base + (s[i++]-'0');// calculate base value for each digit encountered
        }
        return base * sign;
    }
};