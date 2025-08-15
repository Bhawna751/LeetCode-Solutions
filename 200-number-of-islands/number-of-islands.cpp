class Solution {
public:

    int delrow[4] = {0,1,0,-1};
    int delcol[4] = {1,0,-1,0};
    bool valid(int nr, int nc, int n , int m){
        if(nr < 0 || nc < 0 || nr >=n || nc >= m) return false;
        return true;
    }
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size(), m = grid[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr = r+delrow[k];
                int nc = c+delcol[k];
                if(valid(nr,nc,n,m) && grid[nr][nc] == '1' && vis[nr][nc]!=1){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};