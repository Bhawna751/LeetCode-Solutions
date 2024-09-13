class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n == 0 && m == 0) return  0;
        if(n == 0 || m == 0) return  1;
        vector<int> prev(m+1,0), cur(m+1,0);
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }
        for(int i=1;i<=n;i++){
            cur[0] = i;
            for(int j = 1;j<=m;j++){
                if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];
                else cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
            }
            prev = cur;
        }
        return cur[m];
    }
};