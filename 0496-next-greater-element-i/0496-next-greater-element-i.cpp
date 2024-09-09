class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int> mpp;//4,-1  3,4  2,3  1,2
        stack<int>st;// 4 3 2 1
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans; 
        for(auto it: nums1) ans.push_back(mpp[it]);
        return ans;
    }
};