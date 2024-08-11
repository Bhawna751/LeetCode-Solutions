#define v vector
class Solution {
public:

    int regionsBySlashes(vector<string>& g) {
        map<char,vector<vector<int>>> mp;
        mp['/'] = {
            {0,0,1},
            {0,1,0},
            {1,0,0}
        };
        mp['\\'] = {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        };
        mp[' '] = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };

        int nn = g.size(), mm = g[0].size();
        int n = 3*nn, m = 3*mm;
        vector<vector<int>> arr(n, vector<int>(m,0));

        for(int ii=0; ii<nn; ii++)
        for(int jj=0; jj<mm; jj++){
            auto c = g[ii][jj];
            int i = ii * 3, j = jj*3;

            // cout << i << " " << j << "------------\n";
            for(int a=0; a<3; a++  )
            for(int b=0; b<3; b++  ){
                arr[i+a][j+b] = mp[c][a][b];
                // cout << i+a << " " << j+b << "\n";
            }
        }
        
        // for(int i=0; i<n ; i++){
        //     for(int j=0; j<m; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return numIslands(arr);
    }



    bool isValid(v<v<int>>& g, int i, int j){
    int n = g.size(), m = g[0].size();
    return i>=0 and i<n and j>=0 and j<m;
    }
    v<tuple<int,int>> dz = { {-1,0},{1,0},{0,1},{0,-1} };
    vector<vector<bool>> vis;
    void dfs(v<v<int>>& g, int cur_i, int cur_j)
    {
        for(  auto [dx,dy] : dz){
            auto i = cur_i + dx, j = cur_j + dy; 
            if( isValid(g,i,j) and g[i][j]==0 and vis[i][j]==false){
                vis[i][j]=true;
                dfs(g, i,j);
            }
        }   
    }
    int numIslands(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(); int cnt=0;
        vis.assign(310, v<bool>(310,false));
        for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++){
            if(g[i][j]==1 or vis[i][j] ) continue;
            vis[i][j] = true;
            dfs(g, i,j);
            cnt++;
        }
        return cnt;
    }
};