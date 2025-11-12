class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9, cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};