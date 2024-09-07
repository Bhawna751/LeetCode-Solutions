class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        queue<pair<int,pair<int,int>>> q;
        vector<int> minDist(n,1e9);
        q.push({0,{src,0}});
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int stop = p.first;
            int node = p.second.first;
            int dist = p.second.second;
            for(auto it : adj[node]){
                int neighbour = it.first;
                int weight = it.second;
                if(weight + dist < minDist[neighbour] && stop <= k){
                    minDist[neighbour] = weight + dist;
                    q.push({stop + 1,{neighbour,dist+weight}});
                }
            }
        }
        if(minDist[dst] == 1e9) return -1;
        return minDist[dst];
    }
};