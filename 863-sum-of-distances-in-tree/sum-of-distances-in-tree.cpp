class Solution {
private:
    void dfs1(vector<int> adj[],vector<int>&child,int len,int root,vector<int>&vis,vector<int>&dist){
        vis[root]=1;
        dist[0] = dist[0] + len;
        len++;
        for(auto& it: adj[root]){
            if(vis[it]) continue;
            dfs1(adj,child,len,it,vis,dist);
            child[root] = child[root] + child[it];
        }
        child[root] = child[root]+1;
    }
    void dfs2(vector<int>adj[],vector<int>&child,int root,vector<int>&vis,int n, vector<int>&dist){
        vis[root]=1;
        for(auto &it:adj[root]){
            if(vis[it])continue;
            dist[it] = dist[root] - child[it] + n - child[it];
            dfs2(adj,child,it,vis,n,dist);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &edge:edges ){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dist(n),child(n),vis(n);
        dfs1(adj,child,0,0,vis,dist);
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        dfs2(adj,child,0,vis,n,dist);
        return dist;
    }
};