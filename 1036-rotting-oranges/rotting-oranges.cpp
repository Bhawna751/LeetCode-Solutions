class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int total=0, rot=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0)total++;
                if(grid[i][j]==2){
                    rot++;
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                else visited[i][j]=0;
            }
        }
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        int maxi=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            maxi = max(t,maxi);
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                int time=t;
                if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]==1){
                    if(!visited[nr][nc]){
                        visited[nr][nc]=1;
                        q.push({{nr,nc},time+1});
                        grid[nr][nc]=2;
                        cnt++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return maxi;
    }
};