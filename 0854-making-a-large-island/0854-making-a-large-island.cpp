class Solution {
public:
    int explore(vector<vector<int>>&grid,int id, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        return 1 + explore(grid,id,i+1,j) + explore(grid,id,i-1,j)+ explore(grid,id,i,j+1) + explore(grid,id,i,j-1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> size;
        int id=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    size[id] = explore(grid,id,i,j);
                    id++;
                }
            }
        }
        if(size.empty())return 1;
        if(size.size() == 1){
            id--;
            return (size[id] == grid.size()*grid[0].size()) ? size[id] : size[id]+1;
        }
        int maxSize = 1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    int cur = 1;
                    unordered_set<int> neighbour;
                    if(i+1 < grid.size() && grid[i+1][j] > 1) neighbour.insert(grid[i+1][j]);
                    if(i-1 >= 0 && grid[i-1][j] > 1)neighbour.insert(grid[i-1][j]);
                    if(j+1 < grid[0].size() && grid[i][j+1] > 1)neighbour.insert(grid[i][j+1]);
                    if(j-1 >= 0 && grid[i][j-1] > 1)neighbour.insert(grid[i][j-1]);
                    for(int it: neighbour) cur += size[it];
                    maxSize = max(maxSize,cur);
                }
            }
        }
        return maxSize;
    }
};