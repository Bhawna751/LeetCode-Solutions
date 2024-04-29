class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return grid[0][0];
        int m=grid[0].size();
        int sum1=0;
        int col=-1,mini1=0;
        for(auto i = 0;i<grid.size();i++ ){
            auto mini2 = INT_MAX, sum2=INT_MAX, nextcol=-1;
            for(auto j = 0;j<grid.size();j++ ){
                auto smallest = j != col ? mini1 : sum1;
                if(grid[i][j] + smallest < mini2){
                    sum2 = mini2;
                    mini2 = grid[i][j] + smallest;
                    nextcol = j; 
                }
                else{
                    sum2 = min(sum2,grid[i][j]+smallest);
                }
            }
            mini1 = mini2;
            sum1 = sum2;
            col = nextcol;
        }
        return mini1;
    }
};