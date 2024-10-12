class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n==0) return {0};
        else if(n==1) return {0,1};
        ans[0]=0;
        ans[1] =1;
        for(int i=2;i<=n;i++){
            ans[i] = ans[i%2] + ans[i/2];
        }
        return ans;
    }
};