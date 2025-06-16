class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans = -1;
        int pre = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] > pre) ans = max(ans, nums[i]-pre);
            else pre = nums[i];
        }
        return ans;
    }
};