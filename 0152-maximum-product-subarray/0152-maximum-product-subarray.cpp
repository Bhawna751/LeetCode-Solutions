class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = 1, maxi  = 1;
        int ans = -1e9;
        for(int i =0;i<n;i++){
            if(nums[i] < 0){
                swap(maxi,mini);
            }
            mini = min(nums[i]*mini, nums[i]);
            maxi = max(nums[i]* maxi,nums[i]);
            ans = max(ans,maxi);
        }
        return ans;
    }
};