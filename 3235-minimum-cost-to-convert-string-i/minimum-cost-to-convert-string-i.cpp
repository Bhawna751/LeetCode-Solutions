class Solution {
public:
    vector<long long> dijkstra(int start,vector<vector<pair<int,int>>> & adj){
        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0,start});
        vector<long long> minCost(26,-1);
        while(!pq.empty()){
            auto [cost,ch] = pq.top();
            pq.pop();
            if(minCost[ch]!=-1 && minCost[ch] < cost) continue;
            for(auto [target, conversion]: adj[ch]){
                long long total = cost + conversion;
                if(minCost[target] == -1 || total < minCost[target]){
                    minCost[target] = total;
                    pq.push({total,target});
                }
            }
        }
        return minCost;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        int cnt = original.size();
        for(int i=0;i<cnt;i++){
            adj[original[i] - 'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long>> minimumCost(26,vector<long long>(26));
        for(int i = 0;i<26;i++){
            minimumCost[i] = dijkstra(i,adj);
        }
        long long total = 0;
        int n = source.length();
        for(int i=0;i<n;i++){
            if(source[i] != target[i]){
                long long ch = minimumCost[source[i] - 'a'][target[i] - 'a'];
                if(ch == -1) return -1;
                total += ch;
            }
        }
        return total ;
    }
};