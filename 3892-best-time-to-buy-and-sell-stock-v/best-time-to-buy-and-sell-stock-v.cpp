class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long maxi = -1e18;
        vector<vector<long long>> dp1(k+1, vector<long long>(3,maxi));
        dp1[0][0] = 0;
        for(int it:prices){
            vector<vector<long long>> dp2 = dp1;
            for(int i = 0;i<=k;i++){
                if(dp1[i][0]!= maxi) dp2[i][1] = max(dp2[i][1], dp1[i][0] - it);
                if(dp1[i][0]!= maxi) dp2[i][2] = max(dp2[i][2], dp1[i][0] + it);
                if(i < k){
                    if(dp1[i][1] != maxi) dp2[i+1][0] = max(dp2[i+1][0], dp1[i][1] + it);
                    if(dp1[i][2] != maxi) dp2[i+1][0] = max(dp2[i+1][0], dp1[i][2] - it);
                } 
            }
            dp1 = dp2;
        }
        long long ans =0;
        for(int i=0;i<=k;i++){
            ans = max(ans,dp1[i][0]);
        }
        return ans;
    }
};