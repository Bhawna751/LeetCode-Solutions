class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string ans;
        vector<int> pair(n);
        for(int i=0;i<n;i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                int j = st.top();
                st.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        for(int ind=0,dir=1;ind<n;ind += dir){
            if(s[ind] == '(' || s[ind]==')'){
                ind = pair[ind];
                dir = -dir;
            }else{
                ans += s[ind];
            }
        }
        return ans;
    }
};