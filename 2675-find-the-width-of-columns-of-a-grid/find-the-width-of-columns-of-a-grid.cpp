class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n =grid.size();
        int m= grid[0].size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int len = 0;
            int prev=0;
            for(int j=0;j<n;j++){
                int cnt=0;
                if(grid[j][i]<=0){
                    grid[j][i] = abs(grid[j][i]);
                    cnt++;
                }
                if(prev < grid[j][i] || cnt==1){
                    prev = grid[j][i];
                    while(grid[j][i] > 0){
                        cnt++;
                        grid[j][i] = grid[j][i]/10;
                    }
                    if(cnt>len)len=cnt;
                }
            }
            ans[i] = len;
        }
        return ans;
    }
};