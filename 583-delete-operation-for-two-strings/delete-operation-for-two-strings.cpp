class Solution {
public:
    int lcs(string word1, string word2){
        int n =word1.size(), m=word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        for(int ind1=1;ind1<=n;ind1++) {
            for(int ind2 = 1;ind2 <= m; ind2++){
                if(word1[ind1-1] == word2[ind2-1]) dp[ind1][ind2] = 1 +dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m=word2.size();
        int len = lcs(word1, word2);
        return (n-len) + (m-len);
    }
};