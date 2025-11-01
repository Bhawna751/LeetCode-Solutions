class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int grp=(n+k-1)/k;
        vector<string>ans(grp);
        for(int i=0;i<grp;i++){
            string group;
            for(int j=0;j<k;j++){
                int ind = i*k+j;
                if(ind<n){
                    group += s[ind];

                }else group += fill;
            }
            ans[i] = group;
        }
        return ans;
    }
};