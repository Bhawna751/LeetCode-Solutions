class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length(),i=0;
        stack<char> st;
        while (i < n) {
            if (s[i] == '(')
                st.push('(');
            else {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            i++;
        }
         return st.size();
    }
};