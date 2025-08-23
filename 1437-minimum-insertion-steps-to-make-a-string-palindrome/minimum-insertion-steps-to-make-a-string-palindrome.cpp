class Solution {
public:
    int solve(string s, string t){
        int n=s.size(), m= t.size();
        vector<int> cur(m+1,0), prev(m+1,0);
    
        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(s[ind1-1] == t[ind2-1]) cur[ind2] = 1 + prev[ind2-1];
                else cur[ind2] = max(prev[ind2], cur[ind2-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
    int minInsertions(string s) {
        string t =s;
        reverse(s.begin(), s.end());
        int n = s.size();
        int lcs = solve(s,t);
        return n-lcs;
    }
};