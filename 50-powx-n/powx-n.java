class Solution {
    public double solve(double x, long n){
        if(n==0)return 1.0;
        if(n==1)return x;
        if(n%2==0) return solve(x*x, n/2);
        return solve(x,n-1)*x;
    }
    public double myPow(double x, int n) {
        long num=n;
        if(num<0)return 1.0/solve(x,-num);
        return solve(x,num);
    }
}