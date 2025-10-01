class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        for(int it:nums1) mpp[it]++;
        vector<int> ans;
        for(int it:nums2){
            if(mpp.count(it) > 0 && mpp[it]>0){
                ans.push_back(it);
                mpp[it]--;
            }
        }
        return ans;
    }
};