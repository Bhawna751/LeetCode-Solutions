class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix[0].size();//n=2   
        int ans=0;
        for(auto& it: matrix){
            vector<int> flipped(n);
            int cnt=0;
            for(int j=0;j<n;j++)flipped[j]=1-it[j];
            for(auto& iter:matrix){
                if(iter == it || iter == flipped)cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};