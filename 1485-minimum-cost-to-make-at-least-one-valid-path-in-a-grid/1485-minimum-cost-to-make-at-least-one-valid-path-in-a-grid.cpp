class Solution {
public:
    vector<vector<int>> dirr= {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0});
        vector<vector<int>> mincost(n,vector<int>(m,1e9));
        mincost[0][0]=0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0], row=cur[1], col=cur[2];
            if(mincost[row][col]!=cost)continue;
            for(int dir=0;dir<4;dir++){
                int nr = row + dirr[dir][0];
                int nc = col + dirr[dir][1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newcost = cost + (dir != (grid[row][col] -1) ? 1: 0);
                    if(mincost[nr][nc] > newcost){
                        mincost[nr][nc] = newcost;
                        pq.push({newcost,nr,nc});
                    }
                }
            }
        }    
        return mincost[n-1][m-1];
    }
};