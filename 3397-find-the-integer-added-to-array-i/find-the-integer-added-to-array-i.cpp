class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        int x=1e9,y=1e9;
        for(auto i:nums1){
            x=min(x,i);
        }
        for(auto i:nums2){
            y=min(y,i);
        }
            
        
        return y-x;
    }
};