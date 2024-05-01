class Solution {
public:
    int solve(string &s,int ind,int prev,int &k,vector<vector<int>> &dp){
        if(ind>=s.length())return 0;
        if(dp[ind][prev]!=-1)return dp[ind][prev];
        int pick = 0, notpick=0;
        if(prev==0 || abs(s[ind]-prev)<=k){
            pick = 1 + solve(s,ind+1,s[ind],k,dp);
        }
        notpick = solve(s,ind+1,prev,k,dp);
        return dp[ind][prev]=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+1,vector<int>(150,-1));
        return solve(s,0,0,k,dp);
    }
};