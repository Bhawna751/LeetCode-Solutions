class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> dis(n,vector<int>(m,-1));
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int next = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++) {
                pair<int,int> cur = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    pair<int,int> adj = {cur.first + delrow[j], cur.second + delcol[j]};
                    if( adj.first>=0 && adj.first<n && adj.second>=0 && adj.second<m && dis[adj.first][adj.second]==-1){
                    dis[adj.first][adj.second] = next;
                    q.push(adj);
                } 
            }
            }
            next++;
        }
        return dis;
    }
};