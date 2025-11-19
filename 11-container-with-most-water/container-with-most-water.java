class Solution {
    private int min(int a, int b){
        if(a<b)return a;
        else return b;
    }
    private int max(int a, int b){
        if(a<b)return b;
        else return a;
    }
    public int maxArea(int[] height) {
        int n = height.length;
        int l=0,r=n-1;
        int ans=0;
        if(n==2){
            ans=min(height[0],height[1]) * min(height[0],height[1]);
            return ans;
        }
        while(l<r){
            ans=max(ans, min(height[l],height[r]) * (r-l));
            if(height[l]<height[r])l++;
            else r--;
        }
        return ans;
    }
}