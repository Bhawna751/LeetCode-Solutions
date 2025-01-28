class Solution {
public:
    int dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j]=1;
        return grid[i][j] + dfs(grid,vis,i,j+1) +dfs(grid,vis,i+1,j)+dfs(grid,vis,i-1,j)+dfs(grid,vis,i,j-1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]>0){
                    cnt = max(cnt,dfs(grid,vis,i,j));
                }
            }
        }  
        return cnt;
    }
};