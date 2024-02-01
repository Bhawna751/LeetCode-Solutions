class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(2, vector<int>(obstacleGrid[0].size(), 0));
        int curr = 0, pre = 1;

        dp[pre][0] = -1;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            dp[curr][0] = obstacleGrid[i][0] == 1 ? 0 : dp[pre][0];
            for (int j = 1; j < obstacleGrid[i].size(); j++)
                dp[curr][j] = obstacleGrid[i][j] == 1 ? 0 : dp[curr][j - 1] + dp[pre][j];
            
            curr = (curr + 1) % 2;
            pre = (pre + 1) % 2;
        }

        return dp[pre][dp[pre].size() - 1] * -1;
    }
};