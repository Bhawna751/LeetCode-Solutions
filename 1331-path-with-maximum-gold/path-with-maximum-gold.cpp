class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i,int j, int n,int m){
        if(i<0 || j<0 || i == n || j==m|| grid[i][j]==0) return 0;
        int ans=0;
        int val = grid[i][j];
        grid[i][j]=0;
        int delr[] = {0,1,0,-1};
        int delc[] = {1,0,-1,0};
        for(int k = 0;k<4 ; k++){
            ans = max(ans,dfs(grid,delr[k]+i,delc[k]+j,n,m));
        }
        grid[i][j] = val;
        return ans+=val;
    } 
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        
        /* 0 6 0     -1 -1 -1
           5 8 7     -1 -1 -1
           0 9 0     -1 -1 -1
        */
        int ans = -1e9;
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(grid,i,j,n,m));
            }
        }
        return ans;
    }
};