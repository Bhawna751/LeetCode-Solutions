class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        if(m==0)return 0;
        int n = obstacleGrid[0].size();
        if(n==0)return 0;
        if(obstacleGrid[0][0]==1)return 0;
        obstacleGrid[0][0]=1;
        
        for (int i = 1; i <n; i++) {
            obstacleGrid [0][i] = obstacleGrid[0][i] ? 0 : obstacleGrid[0][i-1];
        }
        for (int j = 1; j <m; j++){
            obstacleGrid [j][0] = obstacleGrid[j][0] ? 0 : obstacleGrid[j-1][0];
            for(int ind=1;ind<n;ind++){
                obstacleGrid [j][ind] = obstacleGrid[j][ind] ? 0 : obstacleGrid[j-1][ind] + obstacleGrid[j][ind-1];
            }
        }
        return obstacleGrid[m-1][n-1];   
    }
};