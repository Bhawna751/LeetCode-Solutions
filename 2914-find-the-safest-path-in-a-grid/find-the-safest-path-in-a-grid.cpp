class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isValidCell(vector<vector<int>>& grid,int row, int col){
        int n = grid.size();
        return row<n && col<n && row>=0 && col>=0;
    }
    bool isSafe(vector<vector<int>>& grid, int mini){
        int n=grid.size();
        if(grid[0][0]<mini || grid[n-1][n-1]<mini) return false;
        queue<pair<int,int>> traversal;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        traversal.push({0,0});
        vis[0][0]=true;

        while(!traversal.empty()){
            auto cur = traversal.front();
            traversal.pop();
            if(cur.first == n-1 && cur.second == n-1) return true;
            for(auto &it:dir){
                int drow = cur.first + it[0];
                int dcol = cur.second + it[1]; 
                if(isValidCell(grid,drow,dcol) && !vis[drow][dcol] && grid[drow][dcol] >= mini){
                    vis[drow][dcol] = true;
                    traversal.push({drow,dcol});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        queue<pair<int,int>> pos;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    pos.push({i,j});
                    grid[i][j]=0;
                }
                else grid[i][j]=-1;
            }
        }
        while(!pos.empty()){
            int size = pos.size();
            while(size-- > 0){
                auto cur = pos.front();
                pos.pop();
                for(auto& it:dir){
                    int drow = cur.first + it[0];
                    int dcol = cur.second + it[1];
                    int val = grid[cur.first][cur.second];
                    if(isValidCell(grid,drow,dcol) && grid[drow][dcol] == -1){
                        grid[drow][dcol] = val + 1;
                        pos.push({drow,dcol});
                    } 
                }
            }
        }
        int start=0,end =0,ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                end = max(end,grid[i][j]);
            }
        }
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isSafe(grid,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};