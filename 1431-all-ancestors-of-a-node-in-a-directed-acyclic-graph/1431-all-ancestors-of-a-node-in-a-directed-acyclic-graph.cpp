class Solution {
public:
    void ancestors(int ancestor,vector<vector<int>> &adj,int cur,vector<vector<int>> &ans){
        for(int child:adj[cur]){
            if(ans[child].empty() || 
               ans[child].back() != ancestor){
                ans[child].push_back(ancestor);
                ancestors(ancestor,adj,child,ans);
               }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<vector<int>> ans(n);
        for(int i= 0;i<n;i++){
            ancestors(i,adj,i,ans);
        }
        return ans;
    }
};