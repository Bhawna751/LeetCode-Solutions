class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // 1 2 1 2 3 4 1 3 1 3 1
        // start = 3, target = 1, ans=1
        int n = nums.size();
        int ans=1e9;
        int l=start, r=start;
        while(l>=0){
            if(nums[l]==target){
                ans = min(ans, start-l);
            }
            l--;
        }
        while(r<n){
            if(nums[r]==target){
                ans = min(ans, r-start);
            }
            r++;
        }
        return ans;
    }
};