class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> coordinates;
        int total=0,cnt=0,time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2)coordinates.push({i,j});
            }
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        while(!coordinates.empty()){
            int k = coordinates.size();
            cnt += k;
            while(k--){
                int x=coordinates.front().first;
                int y=coordinates.front().second;
                coordinates.pop();
                for(int dir = 0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    coordinates.push({nx,ny});
                }
            }
            if(!coordinates.empty()) time++;
        }
        return total == cnt ? time : -1;
    }
};