class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain=[](int pass,int total){
            return (double)(pass+1)/(total+1) - (double)(pass)/(total); 
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for(auto it:classes){
            pq.push({gain(it[0],it[1]),{it[0],it[1]}});
        }
        while(extraStudents--){
            auto [cur, info] = pq.top();
            pq.pop();
            int passed=info.first;
            int total = info.second;
            pq.push({gain(passed+1,total+1),{passed+1, total+1}});
        }
        double ans=0;
        while(!pq.empty()){
            auto [_, info]= pq.top();
            pq.pop();
            ans+=(double) info.first / info.second;
        }
        return ans/classes.size();
    }
};