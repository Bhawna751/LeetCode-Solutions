class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> freq(n+1,0), ans(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(++freq[A[i]] == 2) cnt++;
            if(++freq[B[i]] == 2) cnt++;
            ans[i]=cnt;
        }
        return ans;
    }
};