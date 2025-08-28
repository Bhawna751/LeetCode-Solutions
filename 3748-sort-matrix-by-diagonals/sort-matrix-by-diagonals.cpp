class Solution {
public:
    void sortDiagnol(int x, int y, vector<vector<int>>& grid, bool flag,
                     int n) {
        int i = x;
        int j = y;
        vector<int> res;
        while (i < n && j < n) {
            res.push_back(grid[i][j]);
            i++;
            j++;
        }
        if (flag) {
            sort(begin(res), end(res));
        } else {
            sort(rbegin(res), rend(res));
        }
        i = x;
        j = y;
        int k = 0;
        while (i < n && j < n) {
            grid[i][j] = res[k++];
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            sortDiagnol(i, 0, grid, false, n);
        }
        for (int i = 1; i < n; i++) {
            sortDiagnol(0, i, grid, true, n);
        }
        return grid;
    }
};