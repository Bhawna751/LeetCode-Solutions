class Solution {
public:
    vector<int> topoSort(int n, vector<int> adj[]){
        vector<int> inDegree(n,0),ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            for(auto it:adj[cur]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo, adj[n];
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        topo = topoSort(n,adj);
        if(topo.size()<n)return {};
        return topo;
    }
};