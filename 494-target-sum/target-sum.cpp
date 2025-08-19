class Solution {
public:
    int solve(vector<int> &nums, int target, int ind){
        if(ind ==0){
            if(target == 0  && nums[ind]==0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        int notpick = solve(nums, target, ind-1);
        int pick=0;
        if(nums[ind]<=target) pick = solve(nums, target-nums[ind], ind-1);
        return pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total-target < 0 || (total-target)%2==1)return 0;
        int k = (total - target)/2;
        return solve(nums, k, n-1);

    }
};