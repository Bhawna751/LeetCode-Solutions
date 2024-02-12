class Solution {
private:
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp);
        }
        return dp[i][j]=f(i-1,j,s1,s2,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        vector<double>prev(m+1,0),cur(m+1,0);
        
        prev[0]=cur[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    cur[j]=prev[j-1]+prev[j];
                }
                else{
                    cur[j] = prev[j];
                }
            }
            prev=cur;
        }
        return (int)prev[m];
    }
};