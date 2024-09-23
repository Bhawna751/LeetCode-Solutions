class Solution {
public:
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int dp[51]={};
        int n = s.size();
        for(int i= n-1;i>=0 ;i--){
            dp[i] = 1+dp[i+1];
            for(auto it: dictionary){
                if(i + it.size() <= n && s.compare(i, it.size(),it) == 0)
                    dp[i] = min(dp[i], dp[i+it.size()]);
            }
        }
        return dp[0];
    }

};