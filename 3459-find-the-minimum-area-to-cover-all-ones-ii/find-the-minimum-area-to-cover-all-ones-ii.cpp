class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> &grid ){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rotated(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotated[j][n-i-1] = grid[i][j];
            }
        }
        return rotated;
    }
    int area(int r1, int r2, int c1, int c2,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        int maxr = 0, maxc = 0, minr = n-1, minc = m-1;
        for(int i=r1;i<r2;i++){
            for(int j=c1;j<c2;j++){
                if(grid[i][j] == 1){
                    maxr = max(maxr,i);
                    maxc = max(maxc, j);
                    minr = min(minr, i);
                    minc = min(minc, j);
                }
            }
        }
        return (maxr - minr + 1) * ( maxc - minc +1);
    }
    int solve(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1e9;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int top = area(0,i,0,m,grid);
                int bottomLeft = area(i,n,0,j,grid);
                int bottomRight = area(i,n,j,m,grid);

                ans = min(ans, top+bottomLeft+bottomRight);

                int topLeft = area(0,i,0,j,grid);
                int topRight = area(0,i,j,m,grid);
                int bottom = area(i,n,0,m,grid);

                ans = min(ans, topLeft+topRight+bottom);
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int top = area(0,i,0,m,grid);
                int middle = area(i,j,0,m,grid);
                int bottom = area(j,n,0,m,grid);

                ans = min(ans,top+middle+bottom);
            }
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans = solve(grid);
        vector<vector<int>> rotated = rotate(grid);
        ans = min(ans, solve(rotated));
        return ans;
    }
};