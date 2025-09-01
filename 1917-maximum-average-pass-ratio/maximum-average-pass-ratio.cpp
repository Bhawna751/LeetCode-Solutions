class Solution {
public:
    double calculate(int pass, int total){
        return (double)(pass+1)/(total+1) - (double)pass/total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto it:classes){
            pq.push({calculate(it[0],it[1]),{it[0],it[1]}});
        }
        while(extraStudents){
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first + 1;
            int total = top.second.second+1;
            pq.push({calculate(pass,total), {pass,total}});
            extraStudents--;
        }
        double ans=0;
        while(!pq.empty()){
            auto [_,pt] = pq.top();
            pq.pop();
            ans += (double)pt.first / pt.second; 
        }
        return ans/n;
    }
};