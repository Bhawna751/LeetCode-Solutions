class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(auto it=0;it<s.size();it++){
            if(s[it]=='(') st.push(it);
            if(s[it]==')'){
                if(!st.empty()) st.pop();
                else s[it] = '*';
            }
        }
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};