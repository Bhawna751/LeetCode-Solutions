class Solution {
public:
    bool solve(string s, unordered_set<string> &st, int ind, unordered_map<int,bool> &dp){
        if(ind == s.size()) return true; //successfully segmented
        if(dp.find(ind) != dp.end()) return dp[ind];
        for(int i= ind+1;i<=s.size();i++){
            if(st.find(s.substr(ind,i-ind)) != st.end() && solve(s,st,i,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());//"leet" "code"
        unordered_map<int,bool>dp;
        return solve(s, st, 0,dp);
    }
};