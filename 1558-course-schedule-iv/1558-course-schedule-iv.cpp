class Solution {
public:
    bool isPreq(unordered_map<int,vector<int>> &adj,vector<bool>&vis,int src, int target){
        vis[src]=1;
        if(src==target)return true;
        int ans=false;
        for(auto it:adj[src]){
            if(!vis[it]) ans=ans || isPreq(adj,vis,it,target);
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>ans;
        for(auto it:queries){
            vector<bool>vis(numCourses,false);
            ans.push_back(isPreq(adj,vis,it[0],it[1]));
        }
        return ans;
    }
};