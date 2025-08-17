class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1,0);
        dp[0]=1;
        double sum = 0;
        if(k>0)sum= 1;

        for(int i=1;i<=n;i++){
            dp[i] = sum/maxPts;
            if(i<k) sum += dp[i];
            if(i-maxPts >=0 && i-maxPts <k)
                sum = sum-dp[i-maxPts];
                
        }
        double ans=0;
        for(int i=k;i<dp.size();i++){
            ans += dp[i];
        }
        return ans;
    }
};