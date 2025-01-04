class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        for(char it:s){
            st.insert(it);
        }
        int ans=0;
        for(char it:st){
            int i=-1, j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==it){
                    if(i==-1)i=k;
                j=k;
                }
            }
            unordered_set<char> st1;
            for(int k=i+1;k<j;k++) st1.insert(s[k]);
            ans+=st1.size();
        }
        return ans;
    }
};