class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int flag=1;
                for(auto it:mpp){
                    if(it.second<k) flag=0;
                }
                if(flag) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};