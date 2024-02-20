class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minyet=prices[0];
        int maxval = 0;
        for(int i=1;i<prices.size();i++){
            minyet = min(minyet,prices[i]);
            maxval = max(maxval,prices[i]-minyet);
        }
        return maxval;
    }
};