class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>>& visited, int i, int j){
        int delrow[4]={0,1,0,-1};
        int delcol[4]={1,0,-1,0};
        visited[i][j]=1;
        int n = grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if((nr<n && nr >=0 && nc<m && nc>=0)&&grid[nr][nc] =='1' && visited[nr][nc]!=1){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
       vector<vector<int>> visited(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && grid[i][j]=='1'){
                ans++;
                bfs(grid,visited,i,j);
            }
        }
       }
       return ans;
    }
};