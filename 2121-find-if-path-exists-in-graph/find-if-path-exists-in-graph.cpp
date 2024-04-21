class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> gp;
        for(const auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        unordered_set<int> vis;
        return dfs(source,destination,gp,vis);
    }
    bool dfs(int node,int dest, unordered_map<int,vector<int>> &gp,unordered_set<int>&vis){
        if(node == dest) return true;
        vis.insert(node);
        for(int it: gp[node]){
            if(vis.find(it) == vis.end()){
                if(dfs(it,dest,gp,vis)) return true;
            }
        }
        return false;
    }
};