class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> ans;
        for(auto it : nums2){
            if(st.count(it)){
                ans.push_back(it);
                st.erase(it);
            }
        }
        return ans;
    }
};