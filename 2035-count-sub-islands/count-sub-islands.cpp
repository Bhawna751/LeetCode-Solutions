class Solution {
public:
    int dx[4] = {1,0,-1,0}, dy[4]= {0,1,0,-1};
    int n,m;
    bool island(int x, int y, vector<vector<int>> &grid){
        return grid[x][y] == 1;
    }
    bool isSubIsland(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &vis){
        int totalr = grid2.size(), totalc = grid2[0].size();
        int flag = true;
        queue<pair<int,int>> remaining;
        remaining.push({x,y});
        vis[x][y] = true;
        while(!remaining.empty()){
            int curx = remaining.front().first;
            int cury = remaining.front().second;
            remaining.pop();
            if(!island(curx,cury,grid1)) flag=false;
            for(int i=0;i<4;i++){
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];
                if(nextx >=0 && nexty>=0 && nextx<totalr && nexty < totalc && !vis[nextx][nexty] && island(nextx,nexty,grid2)){
                    remaining.push({nextx,nexty});
                    vis[nextx][nexty] = true;
                }
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int totalr = grid2.size(), totalc = grid2[0].size();
        vector<vector<bool>> vis(totalr, vector<bool>(totalc, false));
        int cnt = 0;
        for(int i = 0; i<totalr ;i++){
            for(int j = 0; j<totalc;j++){
                if(!vis[i][j] && island(i,j,grid2) && isSubIsland(i,j,grid1, grid2, vis)){
                    cnt +=1;
                }
            }
        }
        return cnt;
    }
};