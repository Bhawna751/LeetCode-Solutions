class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int rans = -1e9;
        for(int i =0 ;i < n;i++){
            int mini= 1e9;
            for(int j =0 ;j<m;j++){
                mini = min(mini,matrix[i][j]);
            }
            rans = max(rans,mini);
        }
        int cans = 1e9;
        for(int i =0;i<m;i++){
            int maxi = -1e9;
            for(int j = 0;j<n;j++){
                maxi = max(maxi,matrix[j][i]);
            }
            cans = min(cans,maxi);
        }
        if(rans == cans) return {rans};
        return {};
    }
};