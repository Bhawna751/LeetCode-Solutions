class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi =0;
        for(int i=0;i<nums.size();i++){
            int cur = nums[i];
            for(int j=i+1;j<nums.size() && nums[j] > nums[j-1];j++){
                cur += nums[j];
            }
            maxi = max(maxi,cur);
        }
        return maxi;
    }
};