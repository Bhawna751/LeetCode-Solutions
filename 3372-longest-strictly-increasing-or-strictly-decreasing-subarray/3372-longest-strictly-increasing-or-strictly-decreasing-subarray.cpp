class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int maxi = 1;
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                cur++;
                maxi = max(maxi, cur);
            } 
            else cur = 1;
        }
    cur = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            cur++;
            maxi = max(maxi, cur);
        } else {
            cur = 1;
        }
    }

    return maxi;
    }
};