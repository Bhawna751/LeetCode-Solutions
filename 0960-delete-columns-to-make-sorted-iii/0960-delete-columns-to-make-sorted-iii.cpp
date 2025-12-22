class Solution {
public:
    bool compare(vector<string>& strs, int prev, int curr, int n) {
        for (int i = 0; i < n; i++) {
            if (strs[i][prev] > strs[i][curr]) {
                return false;
            }
        }
        return true;
    }
    int solve(vector<string>& strs, int n, int m, int prev, int curr,
    vector<vector<int>>&dp) {
        if (curr == m) return 0;
        if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

        int include = 0;
        if (prev == -1 || compare(strs, prev, curr, n)) {
            include = 1 + solve(strs, n, m, curr, curr + 1,dp);
        }

        int exclude = solve(strs, n, m, prev, curr + 1,dp);

        return dp[prev + 1][curr] = max(include, exclude);
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(m, -1));
        int maxKeep = solve(strs, n, m, -1, 0,dp);
        return m - maxKeep;
    }
};