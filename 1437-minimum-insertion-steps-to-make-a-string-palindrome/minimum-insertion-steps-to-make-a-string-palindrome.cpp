class Solution {
public:
    int solve(string s, string t){
        int n=s.size(), m= t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        string t =s;
        reverse(s.begin(), s.end());
        int n = s.size();
        int lcs = solve(s,t);
        return n-lcs;
    }
};