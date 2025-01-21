class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long r1 = accumulate(begin(grid[0]), end(grid[0]), 0LL);// r1 = 11
        long long r2 = 0; // r2 = 7
        long long mini = LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            r1 -= grid[0][i];//r1 = 4
            mini = min(mini,max(r1,r2));//mini = 8
            r2 += grid[1][i]; // r2 = 
        } 
        return mini;
    }
};