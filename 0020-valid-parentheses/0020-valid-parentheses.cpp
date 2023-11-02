class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i =0;i<s.length();i++){
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{')){
                st.push(s[i]);

            }
            else{
                if(st.size()==0) return false;
                char c =st.top();
                st.pop();
                if((s[i]==')' && c=='(')||(s[i]==']' && c=='[')||(s[i]=='}' && c=='{'))continue;
                else return false;
            }
        }
        return st.empty();
    }
};