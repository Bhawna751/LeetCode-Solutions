class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m=mat[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for (int i = 0; i < n; ++i) {
            int run = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) ++run;
                else run = 0;
                dp[i][j] = run;
            }
        }

        long long ans = 0; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] == 0) continue;
                int minW = INT_MAX;
                for (int k = i; k >= 0; --k) {
                    if (dp[k][j] == 0) break;
                    minW = min(minW, dp[k][j]);
                    ans += (long long)minW;
                }
            }
        }
        return (int)ans;
    }
};