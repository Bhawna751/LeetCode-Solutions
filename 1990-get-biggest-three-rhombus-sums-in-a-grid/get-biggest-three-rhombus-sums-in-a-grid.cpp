class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> tlbr, trbl;
        tlbr = grid, trbl = grid;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                tlbr[i][j] += tlbr[i - 1][j - 1];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m - 1; j++) {
                trbl[i][j] += trbl[i - 1][j + 1];
            }
        }

        set<int> p;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                p.insert(grid[i][j]);
                for(int d = 1; i + 2*d < n && j - d >= 0 && j - 1 >= 0 && j + d < m; d++) {
                    int sw = trbl[i + d][j - d] - trbl[i][j];
                    int se = tlbr[i + 2 * d][j] - tlbr[i + d][j - d];
                    int ne = trbl[i + 2 * d][j] - grid[i + 2 * d][j];
                    if(j + d + 1 != m) {
                        ne = trbl[i + 2 * d][j] - grid[i + 2 * d][j] - trbl[i + d - 1][j + d + 1];
                    } 
                    int nw = tlbr[i + d][j + d] - grid[i + d][j + d];
                    if(i - 1 >= 0) {
                        nw = tlbr[i + d][j + d] - grid[i + d][j + d] - tlbr[i - 1][j - 1];
                    }
                    int sum = sw + se + ne + nw;
                    p.insert(sum);
                }
                while(p.size() > 3)    p.erase(p.begin());
            }
        }
        vector<int> v;
        for(auto &i: p)v.push_back(i);
        sort(v.begin(), v.end(), [] (const int &a, const int &b) {
            return a > b;
        });
        return v;
    }
};