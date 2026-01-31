class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};
        int total = 0, cnt=0, time=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j]==1 || grid[i][j]==2) total++;

            }
        }
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int nx= x + delrow[d];
                    int ny = y + delcol[d];
                    if(nx<0 || ny <0 || nx >= n || ny >= m || grid[nx][ny]!=1)continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) time++;
        }
        return total == cnt ? time : -1;
    }
};