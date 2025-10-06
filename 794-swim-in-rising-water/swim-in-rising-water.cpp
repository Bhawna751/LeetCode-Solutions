class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<vector<int>> visited(n,vector<int>(n,0));

        int dirx[4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0};

        minHeap.push({grid[0][0], 0,0});
        visited[0][0]=1;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int elevation = curr[0];
            int r = curr[1];
            int c = curr[2];
            if(r==n-1 && c==n-1)return elevation;
            for(int i=0;i<4;i++){
                
                    int nr = r + dirx[i];
                    int nc = c + diry[i];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = 1;
                        minHeap.push({max(elevation, grid[nr][nc]), nr, nc});
                    }
                
            }
        }
        return -1;
    }
};