class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        vector<int> adj[n];
        for (auto it : edges) {
            int u = it[0];
            int  v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        dfs(0, -1, adj, values, k, cnt);
        return cnt;
    }
    int dfs(int cur, int parent, vector<int> adj[],
            vector<int> &values, int k, int &cnt) {
        int sum = 0;
        for (auto it : adj[cur]) {
            if (it != parent) {
                sum += dfs(it, cur, adj, values, k,cnt);
                sum %= k; 
            }
        }
        sum += values[cur];
        sum %= k;
        if (sum == 0) cnt++;
        return sum;
    }
};