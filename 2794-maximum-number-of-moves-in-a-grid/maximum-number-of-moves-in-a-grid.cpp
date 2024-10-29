class Solution {
public:
    int dfs(vector<vector<int>> &grid, int n, int m, int i, int j, int prevVal){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] <= prevVal) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int ans = max(dfs(grid,n,m,i-1,j+1,val) , max(dfs(grid,n,m,i,j+1,val), dfs(grid,n,m,i+1,j+1,val)))+1;
        return ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans, dfs(grid,n,m,i,0,-1e6));
        }
        return ans-1;
    }
};