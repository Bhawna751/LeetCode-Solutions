class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0,cnt=1;
        while(n>0){
            int digit = n%10;
            n=n/10;
            if((digit==0 || digit==1) && n>0){
                a += cnt*(1+digit);
                b += cnt*9;
                n--;
            }else{
                a += cnt;
                b += cnt*(digit-1);
            }
            cnt = cnt * 10;
        }
        return {a,b};
    }
};