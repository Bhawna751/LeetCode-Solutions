class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<int> row(n,0), col(m,0);
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = min(rowSum[i] - row[i], colSum[j]-col[j]);
                row[i] += ans[i][j];
                col[j] += ans[i][j];
            }
        }
        return ans;
    }
};