class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();//[10,6,8,5,11,9] 
        vector<int> ans(n);
        stack<int> st;// 0
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] <= heights[i]) {
                ans[st.top()]++;
                st.pop();
            }
            if(!st.empty()) ans[st.top()]++;
            st.push(i);
        }
        return ans;
    }
};