class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long n2=n;
        if(n2<0)n2=-1*n2;
        while(n2){
            if(n2%2){
                ans = ans*x;
                n2=n2-1;
            }
            else{
                x = x*x;
                n2=n2/2;
                
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};