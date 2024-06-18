class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;//{0,0} {2,10} {4,20} {6,30} {8,40} {10,50}
        p.push_back({0,0});
        for(int i = 0; i<difficulty.size(); i++ ){
            p.push_back({profit[i],difficulty[i]});
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        for(int i=0;i<p.size()-1;i++){
            p[i+1].second = min(p[i+1].second,p[i].second);
        }
        int total=0;
        for(int i=0;i<worker.size();i++){
            int job = worker[i];
            int l=0,r=p.size()-1,profit=0;
            while(l <= r){
                int mid = (l+r)/2;
                if(p[mid].second <= job){
                    profit = max(p[mid].first, profit);
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            total += profit;
        }
        return total;
    }
};