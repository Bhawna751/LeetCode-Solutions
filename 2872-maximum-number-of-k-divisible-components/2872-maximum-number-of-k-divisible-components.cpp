class Solution {
public:
    int dfs(vector<int>adj[], vector<int>&values, int k, int &cnt, int cur, int parent){
        int sum=0;//sum=2
        for(auto it:adj[cur]){//it = 1
            if(it!=parent){
                sum += dfs(adj, values, k,cnt,it,cur);
                sum = sum%k;
            }
            
        }
        sum += values[cur];
        sum = sum%k;
        if(sum==0)cnt++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // 0 -> 2
        // 1 -> 2,3
        // 2 -> 1,4,0
        // 3 -> 1
        // 4 -> 2
        int cnt=0;
        dfs(adj,values,k,cnt,0,-1);//(0,0,-1)->(0,2,0)->(0,1,2)->
        return cnt;
    }
};