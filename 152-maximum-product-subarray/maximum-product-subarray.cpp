class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1e9, n = nums.size();
        for(int i=0;i<n;i++){
            int cur = 1;
            for(int j = i;j<n;j++){
                cur *= nums[j];
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};