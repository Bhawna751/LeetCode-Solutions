class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(ch == 'B' && st.top() == 'A') st.pop();
            else if(ch == 'D' && st.top() == 'C') st.pop();
            else st.push(ch);
        }
        return st.size();
    }
};