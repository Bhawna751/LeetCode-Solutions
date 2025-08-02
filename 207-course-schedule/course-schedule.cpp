class Solution {
public:
    bool cycle(vector<int> adj[], vector<int> &vis, int node){
        if(vis[node]==1)return true;
        if(vis[node]==0){
            vis[node]=1;
            for(auto it: adj[node]){
                if(cycle(adj, vis, it)) return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(cycle(adj, vis, i)) return false;
        }
        return true;
    }
};