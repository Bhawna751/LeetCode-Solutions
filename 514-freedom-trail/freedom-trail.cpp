class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &ring, string &key,int dial,int k){
        int n=ring.size(),m=key.size(),steps=1e9;
        if(k>=m) return 0;
        if(dp[k][dial]!=-1)return dp[k][dial];
        for(int i = 0; i<n;i++){
            if(ring[i]==key[k]){
                steps = min(steps,min(abs(i-dial),n-abs(i-dial)) + 1 + solve(ring,key,i,k+1));
            }
        }
        return dp[k][dial]=steps;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size(),m=key.size();
        int dial=0,k=0;
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(ring,key,dial,k);
    }
};