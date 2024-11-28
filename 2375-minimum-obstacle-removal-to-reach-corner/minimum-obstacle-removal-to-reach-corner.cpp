class Solution {
public:

     vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
     bool isValid(vector<vector<int>> &grid, int row,int col){
        return row >=0 && col >= 0 && row < grid.size() && col < grid[0].size();
     }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> obs(n,vector<int> (m,1e9));
        obs[0][0]=grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({obs[0][0],0,0});
        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            int o = cur[0], row = cur[1], col = cur[2];
            if(row == n-1 && col == m-1)return o;
            for(vector<int>&it: dir){
                int nr = row + it[0];
                int nc = col + it[1];
                if(isValid(grid, nr,nc)){
                    int no = o + grid[nr][nc];
                    if(no < obs[nr][nc]){
                        obs[nr][nc] = no;
                        pq.push({no,nr,nc});
                    }
                }

            }
        }
        return obs[n-1][m-1];
    }
};