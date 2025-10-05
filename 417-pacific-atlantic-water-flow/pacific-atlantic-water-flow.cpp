class Solution {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> pacific, atlantic;
    int n,m;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>> &ocean){
        ocean[i][j]=1;

        for(auto it: dirs){
            int x = i + it.first ;
            int y = j + it.second;
            if(x>=0 && y>=0 && x<n && y<m && !ocean[x][y] && matrix[x][y] >= matrix[i][j]){
                dfs(x,y,ocean);
            }
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        matrix = heights;
        n = matrix.size();
        m = matrix[0].size();
        if(n==0) return {};
        vector<vector<int>> ans;
        pacific.assign(n,vector<int>(m,0));
        atlantic.assign(n,vector<int>(m,0));

        for(int i=0;i<n;i++) dfs(i,0,pacific);
        for(int j=0;j<m;j++) dfs(0,j,pacific);
        for(int i=0;i<n;i++) dfs(i,m-1,atlantic);
        for(int j=0;j<m;j++) dfs(n-1,j,atlantic);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};