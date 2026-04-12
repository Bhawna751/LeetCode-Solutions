class Solution {
public:
    vector<vector<int>> mat;
    pair<int,int> pos[26];
    vector<vector<vector<int>>> dp;
    string w;
    int n;

    void helper(){
        mat.assign(26, vector<int>(26));
        for(int i = 0; i < 26; i++) {
            pos[i] = {i/6, i%6};
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                mat[i][j] = abs(pos[i].first - pos[j].first) +
                            abs(pos[i].second - pos[j].second);
            }
        }
    }
    
    int solve(int ind, int f1, int f2)
    {
        if(ind == n)
        return 0;

        if(dp[ind][f1+1][f2+1]!=-1) return dp[ind][f1+1][f2+1];
        int op1 = 0,op2=0;
        if(f1!=-1) op1 = mat[f1][w[ind]-'A'];
        if(f2!=-1) op2 = mat[f2][w[ind]-'A'];
        return dp[ind][f1+1][f2+1] = min(solve(ind+1,w[ind]-'A',f2)+op1,solve(ind+1,f1,w[ind]-'A')+op2);
    }
    int minimumDistance(string word) {
        helper();
        w=word;
        n = word.size();
        dp.assign(n,vector<vector<int>>(27, vector<int>(27,-1)));
        return solve(0,-1,-1);
    }
};