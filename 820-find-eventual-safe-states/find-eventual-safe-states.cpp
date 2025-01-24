class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<bool>&vis, vector<bool>&st, int ind){
        if(st[ind])return true;
        if(vis[ind])return false;
        vis[ind]=true;
        st[ind]=true;
        for(auto it:graph[ind]){
            if(dfs(graph,vis,st,it))return true;
        }
        st[ind]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n), st(n);
        for(int i=0;i<n;i++){
            dfs(graph,vis,st,i);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!st[i])ans.push_back(i);
        }
        return ans;
    }
};