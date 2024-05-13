class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]= grid[i][j]== 0 ? 1:0;
                }
            }
            else continue;
        }
        int sum=0;
        for(int j=0;j<m;j++){
            int cnt0=0,cnt1=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1)cnt1++;
                else cnt0++;
            }
            sum += pow(2, m-j-1) * max(cnt0,cnt1);
        }
        return sum;
    }
};