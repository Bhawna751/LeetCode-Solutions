class Solution {
public:
    int memo[501][501][2][2][5];
    int rows, cols;

    int dfs(int x, int y, int turnUsed, int expected, int dir,
            vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;
        if (memo[x][y][turnUsed][expected][dir] != -1)
            return memo[x][y][turnUsed][expected][dir];

        if (expected == 1 && grid[x][y] != 2)
            return 0;
        if (expected == 0 && grid[x][y] != 0)
            return 0;

        int best = 0;
        if (dir == 1) {
            best = 1 + dfs(x - 1, y + 1, turnUsed, !expected, 1, grid);
            if (!turnUsed)
                best = max(best, 1 + dfs(x + 1, y + 1, 1, !expected, 2, grid));
        } else if (dir == 2) { 
            best = 1 + dfs(x + 1, y + 1, turnUsed, !expected, 2, grid);
            if (!turnUsed)
                best = max(best, 1 + dfs(x + 1, y - 1, 1, !expected, 3, grid));
        } else if (dir == 3) {
            best = 1 + dfs(x + 1, y - 1, turnUsed, !expected, 3, grid);
            if (!turnUsed)
                best = max(best, 1 + dfs(x - 1, y - 1, 1, !expected, 4, grid));
        } else if (dir == 4) { 
            best = 1 + dfs(x - 1, y - 1, turnUsed, !expected, 4, grid);
            if (!turnUsed)
                best = max(best, 1 + dfs(x - 1, y + 1, 1, !expected, 1, grid));
        }

        return memo[x][y][turnUsed][expected][dir] = best;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(memo, -1, sizeof(memo));
        int dX[5] = {0, -1, 1, 1, -1};
        int dY[5] = {0, 1, 1, -1, -1};

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 1; dir <= 4; dir++) {
                        int newX = i + dX[dir];
                        int newY = j + dY[dir];
                        ans = max(ans, 1 + dfs(newX, newY, 0, 1, dir, grid));
                    }
                }
            }
        }
        return ans;
    }
};
