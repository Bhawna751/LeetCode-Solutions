class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), cnt = 0;
        int n = grid[0].size();
        vector<pair<int, int>> temp(n, {0, 0}); 
        for (int i = 0; i < m; i++) {
            int cntX = 0, cntY = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    temp[j].first += 1;
                if (grid[i][j] == 'Y')
                    temp[j].second += 1;
                cntX += temp[j].first;
                cntY += temp[j].second;
                if (cntX >= 1 && cntX == cntY)
                    cnt++;
            }
        }
        return cnt;
    }
};