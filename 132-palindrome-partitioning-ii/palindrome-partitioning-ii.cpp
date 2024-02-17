class Solution {
public:
    int f(int i,int n,string &s,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mincost = 1e9;
        for(int j=i;j<n;j++){
            if(isPalin(i,j,s)){
                int cost = 1+f(j+1,n,s,dp);
                mincost = min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
    bool isPalin(int i,int j,string &s){
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n =s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};