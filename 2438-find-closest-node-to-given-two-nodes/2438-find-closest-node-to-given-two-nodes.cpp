class Solution {
public:
    void dfs(int node, vector<int>&edges, vector<int>& dist, vector<bool>&vis){
        vis[node]=true;
        int neigh = edges[node];
        if(neigh != -1 && vis[neigh]==false){
            dist[neigh] = dist[node]+1;
            dfs(neigh,edges,dist,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        int ans=-1;
        int minDist = 1e9;
        vector<int>d1(n,0), d2(n,0);
        vector<bool> vis1(n,false), vis2(n,false);
        dfs(node1,edges,d1,vis1);
        dfs(node2,edges,d2,vis2); 
        for(int cur = 0; cur<n;cur++){
            if(vis1[cur] == true && vis2[cur]==true && minDist > max(d1[cur], d2[cur])){
                minDist = max(d1[cur],d2[cur]);
                ans=cur;
            }
        }
        return ans;
    }
};