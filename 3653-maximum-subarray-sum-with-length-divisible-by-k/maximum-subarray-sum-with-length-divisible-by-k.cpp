class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const long long INF = (long long)4e18;
        long long ans = -INF, pref = 0;
        vector<long long> mn(k, INF);
        mn[0] = 0;                     

        for (int i = 0; i < (int)nums.size(); ++i) {
            pref += nums[i];
            int r = (i + 1) % k;      
            if (mn[r] != INF)
                ans = max(ans, pref - mn[r]);
            if (pref < mn[r]) mn[r] = pref;
        }
        return ans;
    }
};