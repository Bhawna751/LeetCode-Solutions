class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m=grid[0].size();
        int maxi = 1e9;
        int maxVal = 10000;
        vector<vector<pair<int,int>>> grp(maxVal+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grp[grid[i][j]].push_back({i,j});
            }
        }
        vector<vector<vector<int>>> dist(k+1, vector<vector<int>>(n,vector<int>(m,maxi)));
        dist[0][0][0]=0;
        for(int t=0;t<=k;t++){
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dist[t][i][j]!=maxi){
                        pq.push({dist[t][i][j], i*m+j});
                    }
                }
            }
            while(!pq.empty()){
                auto [d,pos] = pq.top();
                pq.pop();
                int r = pos/m;
                int c = pos%m;
                if(d>dist[t][r][c]) continue;

                int dr[2]={0,1};
                int dc[2] = {1,0};
                for(int i=0;i<2;i++){
                    int nr = r + dr[i];
                    int nc = c+dc[i];
                    if(nr < n && nc < m){
                        if(dist[t][nr][nc] > d + grid[nr][nc]){
                            dist[t][nr][nc] = d+grid[nr][nc];
                            pq.push({dist[t][nr][nc], nr*m+nc});
                        }
                    }
                }
            }
            if(t<k){
                vector<int> minCost(maxVal+1, maxi);
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        minCost[grid[i][j]] =min(minCost[grid[i][j]], dist[t][i][j]);
                    }
                }
                vector<int> suff(maxVal+2, maxi);
                for(int v = maxVal; v >= 0; v--){
                    suff[v]=min(suff[v+1],minCost[v]);
                }
                for (int v = 0; v <= maxVal; ++v) {
                    if (suff[v] == maxi) continue;
                    for (auto& [r, c] : grp[v]) {
                        dist[t + 1][r][c] =
                            min(dist[t + 1][r][c], suff[v]);
                    }
                }
            }
        }
        int ans = maxi;
        for(int t=0;t<=k;t++){
            ans = min(ans, dist[t][n-1][m-1]);

        }
        return ans >= maxi ? -1: ans;
    }
};