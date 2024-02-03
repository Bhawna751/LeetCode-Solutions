class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0),cur(n,0);
        for(int j=0;j<n;j++) prev[j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j-1>=0) ld += prev[j-1];
                else ld += 1e8;
                int rd = matrix[i][j];
                if(j+1<n) rd+=prev[j+1];
                else rd+=1e8;
                cur[j] = min(u,min(ld,rd));
            }
            prev=cur;
        }  
        int mini =1e8;
        for(int j=0;j<n;j++){
            mini = min(mini,prev[j]);

        }
        return mini;
    }
};