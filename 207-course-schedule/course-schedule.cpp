class Solution {
public:
    bool cycle(vector<int>adj[], vector<int>&vis, int node){
        if(vis[node]==1)return true;
        if(vis[node]==0){
            vis[node]=1;
            for(auto it:adj[node]){
                if(cycle(adj, vis, it)) return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(cycle(adj, vis, i)) return false;
        }
        return true;
    }
};