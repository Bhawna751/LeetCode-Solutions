class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int premod=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            premod = (premod+nums[i])%k;
            if(mpp.find(premod) != mpp.end()){
                if (i-mpp[premod]>1) return true;
            }
            else mpp[premod]=i;
        }
        return false;
    }
};