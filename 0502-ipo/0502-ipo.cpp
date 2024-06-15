class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= capital.size();
        vector<pair<int,int>> cp; // (0,1) (1,2) (1,3)
        for(int i=0;i<n;i++){
            cp.push_back({capital[i],profits[i]});
        }
        sort(cp.begin(),cp.end());
        priority_queue<int> pq;// 3 2
        int profit = w, j=0;
        for(int i = 0; i<k ; i++){// i = 1
            while(cp[j].first <= profit && j<n){//0
                pq.push(cp[j].second);
                j++;
            }
            if(pq.size()==0) break;
            profit = profit + pq.top();//profit = 4
            pq.pop();
        }
        return profit;
    }
};