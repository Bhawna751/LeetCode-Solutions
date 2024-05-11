class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        priority_queue<int>pq;
        vector<vector<double>> workers;
        for(int i=0;i<n;i++) workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        sort(workers.begin(),workers.end());
        double ans = DBL_MAX, sum=0;
        for(auto it:workers){
            sum+= it[1];
            pq.push(it[1]);
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = min(ans,sum*it[0]);
            }
        }
        return ans;
    }
};