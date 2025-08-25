class Solution {
public:
    // int solve(string &s, string &t, int ind1 , int ind2,vector<vector<int>> &dp){
    //     if(ind1 < 0) return ind2+1;
    //     if(ind2 < 0) return ind1+1;
    //     if(s[ind1] == t[ind2]) return solve(s, t, ind1-1, ind2-1);
    //     return 1 + min(solve(s,t,ind1-1, ind2), min(solve(s,t,ind1, ind2-1), solve(s,t, ind1-1, ind2-1)));
    // }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] =1 +  min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};