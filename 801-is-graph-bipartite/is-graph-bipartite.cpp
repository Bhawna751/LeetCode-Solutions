class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,0);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(color[i])continue;
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int temp = q.front();
                for(auto it : graph[temp]){
                    if(!color[it]){
                        color[it]= - color[temp];
                        q.push(it);
                    }
                    else if(color[it]==color[temp]) return false;
                }
                q.pop();
            }
        }
        return true;
    }
};