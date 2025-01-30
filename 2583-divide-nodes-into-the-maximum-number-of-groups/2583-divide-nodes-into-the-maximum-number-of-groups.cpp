class Solution {
public:
    bool isBipartite(int node, vector<vector<int>>& adj, vector<int>& visit, int& n){
        vector<int> color(n, -1);
        queue<int> q;
        q.push(node);
        visit[node] = 1;
        color[node] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int uc = color[u];
            for(auto v : adj[u]){
                int vc = (uc == 1) ? 0 : 1;
                if(visit[v] == 0){
                    visit[v] = 1;
                    q.push(v);
                    color[v] = vc;
                }else{
                    if(color[u] == color[v]) return false;
                }
            }
        }
        return true;
    }
    int bfs(int node, vector<vector<int>>& adj, int& n){
        vector<int> visit(n, 0);
        visit[node] = 1;
        queue<int> q;
        q.push(node);
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            while(size){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(visit[v] == 0){
                        visit[v] = 1;
                        q.push(v);
                    }
                }
            size--;
            }
            lvl++;
        }
        return lvl;
    }
    int max_bfs(int node, vector<vector<int>>& adj, vector<int>& visit, vector<int>& max_lvl){
        visit[node] = 1;
        queue<int> q;
        q.push(node);
        int max_ans = 0;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            max_ans = max(max_ans, max_lvl[u]);
            for(auto v : adj[u]){
                if(visit[v] == 0){
                    visit[v] = 1;
                    q.push(v);
                }
            }
        }
        return max_ans;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        n += 1;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visit(n, 0);
        for(int i=1; i<n; i++){
            if(visit[i] == 0){
                if(isBipartite(i, adj, visit, n) == false) return -1;
            }
        }
        vector<int> max_lvl(n, 0);
        for(int i=1; i<n; i++){
            int max_v = 0;
            max_lvl[i] = bfs(i, adj, n);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                ans += max_bfs(i, adj, vis, max_lvl);
            }
        }
        return ans;
    }
};