class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> general(n);
        for(int i=0;i<edges.size();i++){
            general[edges[i][0]].push_back({edges[i][1], succProb[i]});
            general[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int> vis(n,0);
        priority_queue<pair<double, int>> pq;
        pq.push({(double)1.0, start_node});
        vector<double> maxi(n,(double)0.0);
        maxi[start_node]=1.0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            double prob = top.first;
            int node = top.second;
            if(!vis[node]){
                vis[node]++;
                for(auto it: general[node]){
                    if(maxi[it.first] < it.second * prob){
                        maxi[it.first] = it.second * prob;
                        pq.push({maxi[it.first] , it.first});
                    }
                }
            }
        }
        return maxi[end_node];
    }
};