class Solution {
public:
    int lcs(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int j =0;j<=m;j++) prev[j]=0;
        for(int i =0;i<=n;i++) prev[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};