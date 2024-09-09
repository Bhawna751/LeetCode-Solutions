class Solution {
public:
    vector<int> findNSE(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()])st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        
        return ans;
    }
     vector<int> findPSE(vector<int> &heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()])st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights), pse = findPSE(heights);
        int n = heights.size();
        int largest = 0,area;
        for(int i=0;i<heights.size();i++){
            area = (nse[i] - pse[i] - 1) *heights[i];
            largest = max(largest,area);
        }
        return largest;
    }
};