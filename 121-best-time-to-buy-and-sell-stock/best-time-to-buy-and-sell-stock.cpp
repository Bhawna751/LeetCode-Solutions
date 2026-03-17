class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi=-1e9, mini=1e9;
        for(int it:prices){
            mini = min(mini, it);
            maxi = max(maxi,it-mini);
        }
        return maxi;

    }
};