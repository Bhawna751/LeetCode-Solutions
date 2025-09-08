class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0,units=1;
        while(n>0){
            int digit = n%10;
            n=n/10;
            if((digit==0 || digit==1) && n>0){
                a += units*(1+digit);
                b += units*9;
                n--;
            }else{
                a += units;
                b += units*(digit-1);
            }
            units = units * 10;
        }
        return {a,b};
    }
};