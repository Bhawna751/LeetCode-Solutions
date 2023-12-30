class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totaloranges=0,rot=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]>0){
                    totaloranges++;
                }
                if(grid[i][j]==2){
                    rot++;
                    q.push({{i,j},0});
                    vis[i][j]=1; 
                }
                else{
                    vis[i][j]=0;
                }               
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        int maxt=0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int i=0;i<4;i++ ){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                int tm=time;
                if(nrow<rows && nrow>=0 && ncol<cols && ncol>=0 && grid[nrow][ncol]==1){
                    if(!vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},tm+1});
                        grid[nrow][ncol]=2;cnt++;
                    }
                }
                maxt = max(tm,maxt);
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return maxt;
    }
};