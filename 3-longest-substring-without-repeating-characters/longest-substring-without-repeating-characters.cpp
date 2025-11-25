class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256,-1);
        int ans=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(vis[s[r]] >= l) l=vis[s[r]]+1;
            vis[s[r]] = r;
            if(r-l+1 > ans) ans=r-l+1;
        }
        return ans;
    }
};