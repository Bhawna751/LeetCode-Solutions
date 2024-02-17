class Solution {
public:
    int f(int ind,vector<int>&arr,int k,vector<int>&dp){
        int n=arr.size();
        if(ind ==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int len = 0;
        int maxi = -1e9;
        int maxans = -1e9;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len * maxi + f(j+1,arr,k,dp);
            maxans = max(maxans,sum);
        }
        return dp[ind] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n =arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};