class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        vector<int> dist1(n+1, -1), dist2(n+1,-1);
        q.push({1,1});
        dist1[1] = 0;
        while(!q.empty()){
            auto [node,freq] = q.front();
            q.pop();
            int timetaken = freq == 1 ? dist1[node] : dist2[node];
            if((timetaken/change) % 2){
                timetaken = change * (timetaken/change+1) + time;
            }else{
                timetaken = timetaken + time;
            }
            for(auto &it: adj[node]){
                if(dist1[it] == -1){
                    dist1[it] = timetaken;
                    q.push({it,1});
                }else if(dist2[it] == -1 && dist1[it] != timetaken){
                    if(it == n) return timetaken;
                    dist2[it] = timetaken;
                    q.push({it,2});
                }
            }
        }
        return 0;
    }
};