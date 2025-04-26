typedef long l;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        l ans = 0, bad = -1, mini = -1, maxi = -1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK) bad=i;
            if(nums[i] == minK) mini = i;
            if(nums[i] == maxK) maxi = i;
            ans += max(0L,min(mini, maxi)-bad);
        }
        return ans;
    }
};