class Solution {
public:
    const int INF = 2e9;
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long cur = dijsktra(edges, n, source,destination);
        if(cur < target) return {};
        bool flag = (cur == target);
        for(vector<int>& it:edges){
            if(it[2] > 0)continue;
            it[2] = flag ? INF : 1;
            if(!flag){
                long long dist = dijsktra(edges, n, source, destination);
                if(dist <= target){
                    flag = true;
                    it[2] += target - dist;
                }
            }
        }
        return flag ? edges : vector<vector<int>>{};
    }

    long long dijsktra(const vector<vector<int>>& edges,int n, int source, int destination){
        vector<vector<long long>> adj(n,vector<long long>(n,INF));
        vector<long long> minDist(n,INF);
        vector<bool> vis(n,false);
        minDist[source]=0;
        for(const vector<int>& it:edges){
            if(it[2]!=-1){
                adj[it[0]][it[1]] = it[2];
                adj[it[1]][it[0]] = it[2];
            }
        }
        for(int i=0;i<n;i++){
            int nearest = -1;
            for(int j = 0; j < n;j++){
                if(!vis[j] && (nearest==-1 || minDist[j] < minDist[nearest])){
                    nearest = j;
                }
            }
            vis[nearest] = true;
            for(int v = 0;v<n;v++){
                minDist[v] = min(minDist[v], minDist[nearest] + adj[nearest][v]);
            }
        }
        return minDist[destination];
    }
};