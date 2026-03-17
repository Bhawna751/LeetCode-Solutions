class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0 && i > 0) matrix[i][j] += matrix[i-1][j];
            }
            vector<int> cur = matrix[i];
            sort(cur.begin(), cur.end(),greater());
            for(int j=0;j<m;j++){
                ans = max(ans, cur[j] * (j+1));
            }
        }
        return ans;
    }
};