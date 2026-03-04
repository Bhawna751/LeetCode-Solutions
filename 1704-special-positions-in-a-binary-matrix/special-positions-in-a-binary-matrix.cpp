class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < mat.size(); i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            row.push_back(sum);
        }
        for (int i = 0; i < mat[0].size(); i++) {
            int sum = 0;
            for (int j = 0; j < mat.size(); j++) {
                sum += mat[j][i];
            }
            col.push_back(sum);
        }
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    ans += (row[i] == 1 && col[j] == 1) ? 1 : 0;
                }
            }
        }
        return ans;
    }
};