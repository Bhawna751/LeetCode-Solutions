class Solution {
public:
    int f(vector<int> &dp, int n){
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = f(dp,n-1) + f(dp,n-2);
    }
    int climbStairs(int n) {
        int prev = 1, prev2=1;
        for(int i = 2;i<=n;i++){
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};