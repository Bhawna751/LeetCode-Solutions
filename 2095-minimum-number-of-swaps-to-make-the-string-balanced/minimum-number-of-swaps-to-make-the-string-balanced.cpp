class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int swap=0;
        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(c=='[') st.push(c);
            else{
                if(!st.empty()) st.pop();
                else swap++;
            }
        }
        return (swap + 1)/2;
    }
};