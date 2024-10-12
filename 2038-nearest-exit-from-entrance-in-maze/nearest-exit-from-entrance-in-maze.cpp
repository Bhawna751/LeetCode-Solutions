class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{entrance[0], entrance[1]}});
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        while(!q.empty()){
            int steps = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if((x==0 || x==n-1 || y==0||y==m-1)&& !(entrance[0] == x && entrance[1] == y)) return steps;
            for(int i=0;i<4;i++){
                int nr = x + dx[i];
                int nc = y + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc] == '.' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({steps+1, {nr,nc}});
                }
            }
        }
        return -1;
    }
};