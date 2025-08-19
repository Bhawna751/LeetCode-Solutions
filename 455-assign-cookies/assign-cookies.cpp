class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m=s.size();
        int l=0, r=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l<n && r<m){
            if(g[l] <= s[r]) l++;
            r++;
        }
        return l;
    }
};