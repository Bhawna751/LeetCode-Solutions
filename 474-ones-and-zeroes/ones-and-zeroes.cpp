class Solution {
public:
    int dp[601][101][101];
    pair<int,int> count(string s){
        int one=0, zero=0;
        for(char c:s){
            if(c == '1')one++;
            else zero++;
        }
        return {one,zero};
    }
    int solve(int ind,int one, int zero, int &maxZero, int &maxOne, vector<string>& strs){
        if(ind >= strs.size()) return 0;
        if(one > maxOne || zero > maxZero) return 0;
        if(dp[ind][one][zero]!=-1)return dp[ind][one][zero];
        pair<int,int> p = count(strs[ind]);
        int ans1 =0, ans2=0, ans=0;
        if(one + p.first <= maxOne && zero + p.second<= maxZero){
            ans1 = 1+solve(ind+1, one+p.first, zero+p.second, maxZero, maxOne, strs);
            ans2 = solve(ind+1, one,zero,maxZero, maxOne,strs);
        }
        else{
            ans = solve(ind+1, one, zero, maxZero, maxOne, strs);
        
        }
        return dp[ind][one][zero]=max({ans1,ans2,ans});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zero = m, one = n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,zero,one,strs);
    }
};