class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char it: expression){
            if(it == ',' || it == '(') continue;
            if(it == 't' || it == 'f' || it == '&' || it == '|' || it == '!') st.push(it);
            else if(it == ')'){
                bool t=false,f=false;
                while(st.top()!='!' && st.top()!='&' && st.top()!='|'){
                    char top = st.top();
                    st.pop();
                    if(top == 't') t= true;
                    if(top == 'f') f= true;
                }
                char op = st.top();
                st.pop();
                if(op=='!')st.push(t ? 'f' : 't');
                else if(op == '&')st.push(f ? 'f' : 't');
                else st.push(t ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};