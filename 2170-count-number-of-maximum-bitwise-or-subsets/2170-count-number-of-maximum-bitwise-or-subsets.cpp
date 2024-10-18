class Solution {
public:
    int cntSubsets(vector<int> &nums, int ind, int cur, int maxi){
        if(ind == nums.size()) return (cur == maxi) ? 1:0;
        int notpick = cntSubsets(nums,ind+1, cur, maxi);
        int pick = cntSubsets(nums,ind+1, cur|nums[ind], maxi);
        return pick+notpick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int it:nums){
            maxi = max(maxi, it|maxi);
        }
        return cntSubsets(nums,0, 0, maxi);
    }
};