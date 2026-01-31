class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.empty()  ? 0 : st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = st.empty() ? n-1:st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int width = nse[i]-pse[i]+1;
            ans = max(ans,width*heights[i]);
        }
        return ans;

    }
};