class Solution {
public:
    
    int solve(string &s, string &t, vector<vector<int>>&dp, int i, int j){
        if(j < 0)return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i] == t[j]){
            int pick = solve(s,t,dp,i-1,j-1);
            int notpick = solve(s,t,dp,i-1,j);
            ans = pick + notpick;
        }
        else{
            ans = solve(s,t,dp,i-1,j);
        }
        dp[i][j] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,dp,n-1,m-1);
    }
};