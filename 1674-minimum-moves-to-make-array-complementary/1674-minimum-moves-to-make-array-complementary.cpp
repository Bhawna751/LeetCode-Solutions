class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> pref(2 * limit + 5);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int mn = min(a, b);
            int mx = max(a, b);
            int s = a + b;

            pref[2] += 2;
            pref[mn + 1] -= 1;
            pref[s] -= 1;
            pref[s + 1] += 1;
            pref[mx + limit + 1] += 1;
        }

        int ans = 1e9;
        int curr = 0;

        for (int i = 2; i <= 2 * limit; i++) {
            curr += pref[i];
            ans = min(ans, curr);
        }

        return ans;
    }
};