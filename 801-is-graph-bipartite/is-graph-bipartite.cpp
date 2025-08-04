class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>> &graph, vector<int>& color){
        color[node]=col;
        for(auto it: graph[node]){
            if(color[it] == -1){
                if(!dfs(it, !col, graph, color)) return false;
            }
            else if(color[it] == col)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(!dfs(i, 0, graph, color)) return false;
            }
        }
        return true;
    }
};