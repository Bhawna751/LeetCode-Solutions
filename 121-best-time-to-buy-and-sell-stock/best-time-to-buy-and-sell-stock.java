class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int ans = 0;
        int minPrice=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            minPrice = Math.min(minPrice, prices[i]);
            ans= Math.max(ans,prices[i]-minPrice);
        }
        return ans;
    }
}