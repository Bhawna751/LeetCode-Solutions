class Solution {
public:
    bool connected(int src, int target, vector<bool>&vis, vector<int> adj[]){
        vis[src]=true;
        if(src==target)return true;
        int flag=false;
        for(int it:adj[src]){
            if(!vis[it]) flag = flag || connected(it,target,vis,adj);
        }
        return flag;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(auto it:edges){
            vector<bool>vis(n,false);
            if(connected(it[0]-1, it[1]-1,vis,adj)) return it;
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        return {};
    }
};