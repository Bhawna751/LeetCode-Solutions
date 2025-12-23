class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(auto it:tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(it == "+") st.push(a+b);
                else if(it == "-") st.push(b-a);
                else if(it == "*") st.push(a*b);
                else st.push(b/a);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};