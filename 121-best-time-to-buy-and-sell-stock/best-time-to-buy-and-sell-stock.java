class Solution {
    public int maxProfit(int[] prices) {
        int maxPro=0, minPrice=Integer.MAX_VALUE;
        int n = prices.length;
        for(int i=0;i<n;i++){
            if(minPrice > prices[i]){
                minPrice=prices[i];
            }
            maxPro = Math.max(maxPro,prices[i]-minPrice);
        }
        return maxPro;
    }
}