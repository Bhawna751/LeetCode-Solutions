class Solution {
public:
    int numOfWays(int n) {
        int mod=1e9+7;
        vector<vector<vector<int>>> dp(3,vector<vector<int>>(3,vector<int>(3,0)));
        for(int i=0; i< 3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(i==j) continue;
                for(int k=0; k<3; k++)
                {
                    if(j==k) continue;
                    dp[i][j][k]=1;
                }
            }
        }
        for(int t=1; t<n; t++)
        {
            vector<vector<vector<int>>> clone(3,vector<vector<int>>(3,vector<int>(3,0)));
            for(int i=0;i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(i==j) continue;
                    for(int k=0;k<3; k++)
                    {
                        if(j==k) continue;
                        for(int pi=0; pi<3; pi++)
                        {
                            if(pi==i) continue;
                            for(int pj=0; pj<3; pj++)
                            {
                                if(pj==j|| pj==pi) continue;
                                for(int pk=0; pk<3; pk++)
                                {
                                    if(pk==k || pk==pj) continue;
                                    clone[i][j][k]=(1LL*clone[i][j][k]+dp[pi][pj][pk])%mod;
                                }
                            }
                        }
                    }
                }
            }
            swap(dp,clone);
        }
        int ans=0;
        for(int i=0; i< 3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    ans=(1LL*ans+dp[i][j][k])%mod;
                }
            }
        }
        return ans;

    }
};