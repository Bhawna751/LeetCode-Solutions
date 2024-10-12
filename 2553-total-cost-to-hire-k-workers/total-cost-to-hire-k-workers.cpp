class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int> > first,second;
        for(int i=0;i<candidates;i++){
            first.push(costs[i]);//7 10 12 17 
        }
        int maxi = max(candidates,n - candidates);// maxi = 5
        for(int i=maxi;i<costs.size();i++){
            second.push(costs[i]);// 8 11 20
        }
        long long ans=0;// ans = 4
        int nextFirst = candidates;//nf = 5
        int nextSecond = n - candidates - 1;//ns = 5
        for(int i=0;i<k;i++){
            if(second.empty() || !first.empty() && first.top() <= second.top()){
                ans += first.top();
                first.pop();
                if(nextSecond >= nextFirst ){
                    first.push(costs[nextFirst]);
                    nextFirst++;
                }
            }
            else{
                ans += second.top();
                second.pop();
                if(nextSecond >= nextFirst ){
                    second.push(costs[nextSecond]);
                    nextSecond--;
                }
            }
        }
        return ans;
    }
};