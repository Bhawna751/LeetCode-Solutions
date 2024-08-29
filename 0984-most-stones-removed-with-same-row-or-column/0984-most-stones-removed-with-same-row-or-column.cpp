class Solution {
public:
    void dfs(int n, int ind, vector<bool>& vis, vector<vector<int>>& stones) {
        vis[ind] = true;
        for (int i = 0; i < n; i++) {
           
                if (!vis[i]) {
                    if (stones[ind][0] == stones[i][0])
                        dfs(n, i, vis, stones);
                    if (stones[ind][1] == stones[i][1])
                        dfs(n, i, vis, stones);
                }
            
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int grp = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(n, i, vis, stones);
                grp++;
            }
        }
        return n - grp;
    }
};