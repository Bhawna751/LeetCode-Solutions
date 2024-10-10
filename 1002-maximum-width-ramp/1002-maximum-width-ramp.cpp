class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();//[9,8,1,0,1,9,4,0,4,1]
        stack<int> st;//1 0
        for(int i=0;i<n;i++){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        int maxi = 0;//maxi = 7
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }
        return maxi;
    }
};