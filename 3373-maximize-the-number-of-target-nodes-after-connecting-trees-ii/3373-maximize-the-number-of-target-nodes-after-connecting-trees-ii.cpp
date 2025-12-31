class Solution {
public:
    void bfs(int n, vector<vector<int>>& adj, vector<int>& ans, int parityStart) {
        vector<int> visited(n, 0), levelCount(2, 0);
        queue<int> q;
        q.push(0); visited[0] = 1;
        int level = parityStart;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front(); q.pop();
                levelCount[level]++;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        q.push(v);
                    }
                }
            }
            level ^= 1;
        }

        fill(visited.begin(), visited.end(), 0);
        q.push(0); visited[0] = 1;
        ans[0] = levelCount[parityStart];
        level = 1 - parityStart;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        ans[v] = levelCount[level];
                        q.push(v);
                    }
                }
            }
            level ^= 1;
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) adj1[e[0]].push_back(e[1]), adj1[e[1]].push_back(e[0]);
        for (auto& e : edges2) adj2[e[0]].push_back(e[1]), adj2[e[1]].push_back(e[0]);

        vector<int> ans1(n), ans2(m);
        bfs(n, adj1, ans1, 1);  
        bfs(m, adj2, ans2, 0);  

        int maxVal = *max_element(ans2.begin(), ans2.end());
        for (int& x : ans1) x += maxVal;

        return ans1;
    }
};