class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
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
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int st  = q.front().second;
            q.pop();
            dis[row][col]=st;
            for(int i=0;i<4;i++){
                int r = row+delrow[i];
                int c = col+delcol[i];
                int s = st;
                if( r>=0 && r<n && c>=0 && c<m && mat[r][c]!=0){
                    if(vis[r][c]!=1){
                        vis[r][c]=1;
                        q.push({{r,c},s+1});
                        dis[r][c]=s;
                    }
                } 
            }
        }
        return dis;
    }
};