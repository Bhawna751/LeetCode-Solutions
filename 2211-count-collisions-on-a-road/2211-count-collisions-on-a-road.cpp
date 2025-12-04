class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<directions.size();i++){
            char c=directions[i];
            if(c=='L'){
                if(!st.empty() && st.top() == 'R'){
                    st.pop();
                    ans += 2;
                    c='S';
                    while(!st.empty() && st.top()=='R'){
                        st.pop();
                        ans++;
                    }
                }
                else if(!st.empty() && st.top()=='S'){
                    ans++;
                    c='S';
                }
                else continue;
            }
            else if(c=='S'){
                while(!st.empty() && st.top()=='R'){
                        st.pop();
                        ans++;
                    }
            }
            if(c=='R' || c=='S')st.push(c);
        }
        return ans;
    }
};