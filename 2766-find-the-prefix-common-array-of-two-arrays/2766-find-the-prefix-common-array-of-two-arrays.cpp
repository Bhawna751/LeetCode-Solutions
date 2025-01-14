class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_set<int> st1, st2;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            st1.insert(A[i]);
            st2.insert(B[i]);
            int cnt=0;
            for(int it:st1){
                if(st2.count(it)) cnt++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};