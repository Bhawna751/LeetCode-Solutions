class Solution {
public:
    int GCD(int num, int denom){
        if( num == 0) return denom;
        return GCD(denom % num, num);
    }
    string fractionAddition(string expression) {
        int n =0, d = 1, i=0;
        while(i<expression.size()){
            int curn = 0, curd = 0;
            bool neg = false;
            if(expression[i] == '+' || expression[i] == '-'){
                if (expression[i] == '-') neg = true;
                i++;
            }
            while(isdigit(expression[i])){
                int digit = expression[i] - '0';
                curn = curn * 10 + digit;
                i++;
            }
            if(neg) curn *= -1;
            i++;
            while(i<expression.size() && isdigit(expression[i])){
                int digit = expression[i] - '0';
                curd = curd * 10 + digit;
                i++;
            }
            n = n*curd + curn*d;
            d *= curd;
        }
        int gcd = abs(GCD(n,d));
        n /= gcd;
        d /=gcd;
        return to_string(n) + "/" + to_string(d);
    }
};