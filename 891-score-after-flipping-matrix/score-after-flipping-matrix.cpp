class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++) grid[i][j]=1-grid[i][j];
            }
        }
        for(int j=1;j<m;j++){
            int cnt0 =0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0)cnt0++;
            }
            if(cnt0 > n-cnt0){
                for(int i=0;i<n;i++) grid[i][j] = 1-grid[i][j];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int colsum = grid[i][j] << (m-j-1);
                sum += colsum;
            }
        }
        return sum;
    }
};