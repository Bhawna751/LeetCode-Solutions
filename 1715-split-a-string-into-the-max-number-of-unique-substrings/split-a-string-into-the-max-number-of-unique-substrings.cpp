class Solution {
public:
    unordered_set<string> st;
    int n, maxcnt=0;
    void f(int ind, string s,int cnt){
        if(ind>=n){
            maxcnt = max(maxcnt, cnt);
            return;
        }
        
        for(int i = ind; i<n ;i++){
            string substr = s.substr(ind,i-ind+1);
            if(st.count(substr)) continue;
            st.insert(substr);
            f(i+1,s,cnt+1);
            st.erase(substr);
        }
    }
    int maxUniqueSplit(string s) {
        n=s.length();
        int cnt=0;
        f(0,s,cnt);
        return maxcnt;
    }
};