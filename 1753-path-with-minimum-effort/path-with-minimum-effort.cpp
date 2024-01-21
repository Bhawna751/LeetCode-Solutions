class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int row= heights.size();
        int col = heights[0].size();
        vector<vector<int>> dist(row,vector<int> (col,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int n= it.second.first;
            int m = it.second.second;
            if(n==row-1 && m == col-1) return diff;
            for(int i=0;i<4;i++){
                int nr = n + dr[i];
                int nc = m + dc[i];
                if(nr>=0 && nr<row && nc>=0 && nc<col){
                    int neweff = max(abs(heights[n][m]-heights[nr][nc]),diff);
                    if(neweff < dist[nr][nc]){
                        dist[nr][nc]=neweff;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};