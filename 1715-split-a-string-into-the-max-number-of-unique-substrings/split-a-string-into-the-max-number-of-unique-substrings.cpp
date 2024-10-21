class Solution {
public:
    int f(int ind, string s, unordered_set<string> &st){
        if(ind==s.length())return 0;
        int cnt=0;
        for(int i = ind+1; i<=s.length();i++){
            string substr = s.substr(ind,i-ind);
            if(st.find(substr)==st.end()){
                st.insert(substr);
                cnt = max(cnt, 1+f(i,s,st));
                st.erase(substr);
            }
        }
        return cnt;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return f(0,s,st);
    }
};