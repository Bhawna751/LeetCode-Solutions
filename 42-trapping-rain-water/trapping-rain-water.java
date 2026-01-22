class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int l=0, h=n-1;
        int ans=0;
        int lmax=0, rmax=0;
        while(l<h){
            if(height[l] <= height[h]){
                if(lmax > height[l]){
                    ans += lmax - height[l];
                }
                else lmax = height[l];
                l++;
            }
            else{
                if(rmax > height[h]) ans += rmax - height[h];
                else rmax = height[h];
                h--;
            }
        }
        return ans;
    }
}