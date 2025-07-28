class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int maxPro=0, minPrice=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            minPrice = Math.min(minPrice, prices[i]);
            maxPro = Math.max(maxPro, prices[i]-minPrice);
        }
        return maxPro;
    }
}