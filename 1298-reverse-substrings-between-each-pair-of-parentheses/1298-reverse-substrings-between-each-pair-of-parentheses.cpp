class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string ans;
        for(char it : s){
            if(it == '('){
                st.push(ans.length());
            }else if(it == ')'){
                int start = st.top();
                st.pop();
                reverse(ans.begin() + start, ans.end());
            }else{
                ans += it;
            }
        }
        return ans;
    }
};