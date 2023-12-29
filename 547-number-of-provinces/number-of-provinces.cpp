class Solution {
private:
    void dfs(int node,vector<vector<int>> &adjls,int* vis){
        vis[node]=1;
        for(auto it: adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        int V = isConnected.size();
        vector<vector<int>> adjls(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                   // adjls[j].push_back(i);
                }
            }
        }
        int vis[V];
        memset(vis,0,V*sizeof(int));
        int cnt =0;
        for(int i =0; i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};