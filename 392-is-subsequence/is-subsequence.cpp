class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= s.size(), m=t.size();
        
        int j=0;
        for(int i=0;i<m && j<n;i++){
            if(t[i]==s[j])j++;
        }
        return (j==n);
    }
};