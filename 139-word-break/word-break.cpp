class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());//"leet" "code"
        vector<bool>dp(s.length()+1,false);
        dp[0]=true; // An empty string can always be segmented
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.find(s.substr(j,i-j)) != st.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};