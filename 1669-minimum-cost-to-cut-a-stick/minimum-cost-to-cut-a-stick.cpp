class Solution {
public:
    int dp[101][101];
    int f(int i,int j,vector<int>&cuts,int left,int right){
        if(left>right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
        int cost=1e9;
        for(int k=left;k<=right;k++){
            int leftc = f(i,cuts[k],cuts,left,k-1);
            int rightc = f(cuts[k],j,cuts,k+1,right);
            int cc=(j-i)+leftc+rightc;
            cost = min(cost,cc);
        }
        return dp[left][right]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return f(0,n,cuts,0,cuts.size()-1);
    }
};