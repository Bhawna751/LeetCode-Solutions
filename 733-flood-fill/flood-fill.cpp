class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>&image, int sr, int sc, int color, int origin){
        int n = image.size(), m=image[0].size();
        image[sr][sc] = color;
        for(int i=0;i<4;i++){
            int nr = sr+delrow[i];
            int nc = sc+delcol[i];
            if(nr >=0 && nc >=0 && nr<n && nc<m && image[nr][nc]==origin){
                dfs(image, nr, nc, color, origin);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origin = image[sr][sc];
        if(color == origin) return image;
        dfs(image, sr, sc, color , origin);
        return image;
    }
};