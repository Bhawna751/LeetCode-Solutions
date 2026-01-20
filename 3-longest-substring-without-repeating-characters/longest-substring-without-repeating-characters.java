class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans =0 ;
        int[] vis = new int[256];
        Arrays.fill(vis,-1);
        int l=0;
        for(int i=0;i<s.length();i++){
            if(vis[s.charAt(i)] >= l) {
                l = vis[s.charAt(i)] + 1; 
            }
            vis[s.charAt(i)] = i;
            if(i-l+1 > ans) ans = i-l+1;
        }
        return ans;
    }
}