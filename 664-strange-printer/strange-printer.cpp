class Solution {
public:
    int solve(int i, int j,string &s, vector<vector<int>> &dp){
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int k =i;k<j;k++){
            mini = min(mini,solve(i,k,s,dp) + solve(k+1,j,s,dp));
        }
        return dp[i][j] = s[i] == s[j] ? mini-1:mini;
    }
    int strangePrinter(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solve(0,s.length()-1,s,dp);
    }
};