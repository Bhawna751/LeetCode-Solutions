class Solution {
public:
    int coordinates(int x,int y){
        return x + 60013 * y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obs;
        for(auto it:obstacles){
            obs.insert(coordinates(it[0],it[1]));
        }
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> cur = {0,0};
        int dist = 0, curdir = 0;
        for(int it:commands){
            if(it == -1){
                curdir = (curdir + 1)%4;
                continue;
            }
            if(it == -2){
                curdir = (curdir+3)%4;
                continue;
            }
            vector<int> directions = dir[curdir];
            for(int i = 0;i<it;i++){
                int nextX = cur[0] + directions[0];
                int nextY = cur[1] + directions[1];
                if(obs.contains(coordinates(nextX, nextY)))break;
                cur[0] = nextX;
                cur[1] = nextY;
            }
            dist = max(dist,cur[0] * cur[0]+cur[1]*cur[1]);
        }
        return dist;
    }
};