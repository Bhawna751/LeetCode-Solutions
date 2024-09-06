class Solution {
public:
    // int solve(string &word1, string &word2, int i, int j,vector<vector<int>>&dp){
    //     if(i<0)return j+1;
    //     if(j<0)return i+1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(word1[i] == word2[j]) return dp[i][j] = solve(word1,word2,i-1,j-1,dp);
    //     else return dp[i][j] = 1 + min(solve(word1,word2,i-1,j-1,dp),min(solve(word1,word2,i-1,j,dp),solve(word1,word2,i,j-1,dp)));

    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length(), m=word2.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return solve(word1,word2,n-1,m-1,dp);
    // }
// TABULATION:
    // int minDistance(string word1, string word2){
    //     int n=word1.length(), m=word2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int i=0;i<=n;i++) dp[i][0] = i;
    //     for(int i=0;i<=m;i++)dp[0][i] = i;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //             else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
    //         }
    //     }
    //     return dp[n][m];
    // }


    int minDistance(string word1, string word2){
        int n=word1.length(), m=word2.length();
        if(n==0 && m==0) return 0;
        if(m==0 || n==0) return 1;
        vector<int> prev(m+1,0), cur(m+1,0);
        
        for(int i=0;i<=m;i++)prev[i] = i;

        for(int i=1;i<=n;i++){
            cur[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    cur[j] = prev[j-1];
                }
                else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev=cur;
        }
        return cur[m];
    }

};