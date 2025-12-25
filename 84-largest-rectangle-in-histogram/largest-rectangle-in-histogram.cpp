class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int>st;
        int ans = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int cur = heights[st.top()];
                st.pop();
                int pse;
                if(st.empty()) pse = -1;
                else pse = st.top();
                int area = cur * ((i-1)-(pse+1)+1);
                ans = max(ans,area);
            }
            st.push(i);
        }   
        return ans;
    }
};