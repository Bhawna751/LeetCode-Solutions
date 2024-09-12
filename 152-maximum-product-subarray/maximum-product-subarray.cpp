class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mini = 1, maxi = 1;
        int ans = -1e9;
        for (int j = 0; j < n; j++) {
            if(nums[j] < 0){
                swap(maxi,mini);
            }
            maxi = max(maxi*nums[j], nums[j]);
            mini = min(mini*nums[j], nums[j]);
            ans = max(ans, maxi);
        }

        return ans;
    }
};