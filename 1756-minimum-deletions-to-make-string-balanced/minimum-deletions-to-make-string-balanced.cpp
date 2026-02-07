class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> freqA(n,0);
        vector<int> freqB(n,0);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            freqB[i] = b;
            if(s[i]=='b')b++;
        }
        for(int i=n-1;i>=0;i--){
            freqA[i] = a;
            if(s[i]=='a')a++;
        }
        int op = n;
        for(int i=0;i<n;i++){
            op = min(op, freqA[i] + freqB[i]);
        }
        return op;
    }
};