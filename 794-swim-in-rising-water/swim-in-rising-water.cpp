
class Solution {

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans = max(grid[0][0],grid[n-1][n-1]);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        pq.push({ans,0,0});
                
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans = max(ans,it[0]);
            queue<pair<int,int>> q;
            q.push({it[1],it[2]});
            while(!q.empty()){
                auto iter = q.front();
                q.pop();
                if(iter.first == n-1 && iter.second == n-1)return ans;
                for(int i=0;i<4;i++){
                    int nr = iter.first + dr[i];
                    int nc = iter.second + dc[i];
                    if(nr>=0 && nr< n && nc>=0 && nc<n && vis[nr][nc]==0){
                        vis[nr][nc]=1;
                        if(grid[nr][nc]<= ans){
                            q.push({nr,nc});
                        }
                        else{
                            pq.push({grid[nr][nc],nr,nc});
                        }
                    }
                }
            }
        }
        return -1;
    }
};