class Solution {
public:
    int lcs(string str1,string str2){
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int j = 0;j<=m;j++)prev[j]=0;
        for(int i = 0;i<=n;i++)cur[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};