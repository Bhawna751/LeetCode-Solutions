class Solution {
public:
//MEMO: 
    // int solve(string &text1, string &text2, int i,int j,vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(text1[i] == text2[j]) return dp[i][j] = 1+ solve(text1,text2,i-1,j-1,dp);
    //     else return dp[i][j] = max(solve(text1,text2,i,j-1,dp), solve(text1,text2,i-1,j,dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n=text1.size(), m=text2.size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return solve(text1,text2,n-1,m-1,dp);
    // }
//  TABULATION: 
//     int longestCommonSubsequence(string text1, string text2){
//         int n=text1.size(), m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         for(int i=0;i<=n;i++){
//             dp[i][0]=0;
//         }
//         for(int i=0;i<=m;i++){
//             dp[0][i]=0;
//         }
//         for(int i = 1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[n][m];
//     }
// };
    int longestCommonSubsequence(string text1, string text2){
        int n=text1.size(), m=text2.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};