class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
        if(n<2)return 0;
        for(int i=0,j=1;j<n;j++){
            if(prices[i] < prices[j]){
                while(j+1<n && prices[j]<prices[j+1])j++;
                ans += prices[j]-prices[i];
            }
            i=j;
        }
        return ans;
    }
};