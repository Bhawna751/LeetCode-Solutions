class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> cnta(n,0);
        vector<int> cntb(n,0);
        int b = 0,a=0;
        for(int i=0;i<n;i++){
            cntb[i] = b;
            if(s[i]=='b') b++; 
        }
        for(int i=n-1;i>=0;i--){
            cnta[i] = a;
            if(s[i]=='a') a++; 
        }
        int op = n;
        for(int i=0;i<n;i++){
            op = min(op,cnta[i] + cntb[i]);
        }
        return op;
    }
};