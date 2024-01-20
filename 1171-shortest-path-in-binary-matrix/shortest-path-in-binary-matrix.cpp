struct Point{
    int x;
    int y;
    int cnt;
};
class Solution {
public:
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid[0][0]==1) return -1;
        int row = grid.size();
        int col = grid[0].size();
        grid[0][0]=-1;
        queue<Point>q;
        q.push({0,0,1});
        
        while(!q.empty()){
            Point p =q.front();
            q.pop();
            if (p.x == row-1 && p.y == col-1) return p.cnt;
            for(int i=0;i<8;i++){
                int x = p.x + dx[i];
                int y = p.y + dy[i];
                if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==0){
                    grid[x][y]=-1;
                    q.push({x,y,p.cnt+1});
                }
            }
        }
        return -1;
        
    }
};