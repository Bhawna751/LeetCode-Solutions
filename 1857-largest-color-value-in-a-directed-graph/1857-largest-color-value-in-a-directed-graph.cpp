class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>graphs(n,vector<int>());
        vector<int>indegree(n);
        for(vector<int>&edge : edges){
            graphs[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int>zero;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                zero.push(i);
            }
        }
        vector<vector<int>>count(n,vector<int>(26));
        for(int i=0;i<n;i++){
            count[i][colors[i] - 'a']++;
        }
        int visited = 0;
        int max_count = 0;
        while(!zero.empty()){
            int u = zero.front();
            zero.pop();
            visited++;
            for(int v: graphs[u]){
                for(int j=0;j<26;j++){
                    count[v][j] = max(count[v][j], count[u][j] + (colors[v]-'a' == j?1:0));
                }
                indegree[v]--;
                if(indegree[v] == 0){
                    zero.push(v);
                }
            }
            max_count = max(max_count, *max_element(count[u].begin(),count[u].end()));
        }
        return visited == n? max_count:-1;
    }
};