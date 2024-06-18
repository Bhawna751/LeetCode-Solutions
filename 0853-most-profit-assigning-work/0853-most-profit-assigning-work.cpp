class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> p;//{2,10} {4,20} {6,30} {8,40} {10,50}
        
        for(int i = 0; i<difficulty.size(); i++ ){
            p.push_back({difficulty[i],profit[i]});
        }
        
        sort(p.begin(),p.end());
        sort(worker.begin(),worker.end());// 4 5 6 7

        int net=0,maxi=0,ind=0;
        for(int i=0;i<worker.size();i++){
            while(ind<difficulty.size() && worker[i]>= p[ind].first){
                maxi = max(maxi,p[ind].second);//20
                ind++;//2
            }
            net += maxi;//20
        }
        return net;
    }
};