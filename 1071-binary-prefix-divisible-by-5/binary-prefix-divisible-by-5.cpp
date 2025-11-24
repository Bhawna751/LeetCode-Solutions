class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int  n= nums.size();
        vector<bool>ans;
        int remainder=0;
        for(int it:nums){
            remainder = (((remainder%5)<<1) + it) % 5;
            if(remainder==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};