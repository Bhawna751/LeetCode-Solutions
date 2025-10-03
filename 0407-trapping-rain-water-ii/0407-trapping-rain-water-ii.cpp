class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int n=heightMap.size(), m=heightMap[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0], {i,0}});
            vis[i][0] = 1;
            pq.push({heightMap[i][m-1], {i,m-1}});
            vis[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            pq.push({heightMap[0][j], {0,j}});
            pq.push({heightMap[n-1][j], {n-1,j}});
            vis[0][j] = 1;
            vis[n-1][j]=1;
        }
        int ans=0;
        while(!pq.empty()){
            auto node = pq.top();
            int mn = node.first;
            int i=node.second.first;
            int j=node.second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    if(heightMap[nr][nc] < mn){
                        ans += mn - heightMap[nr][nc];
                        pq.push({mn,{nr,nc}});
                    }
                    else pq.push({heightMap[nr][nc], {nr,nc}});
                    
                }
            }
        }
        return ans;
    }
};