class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> indices(n, 0);
        vector<int> range = {0,INT_MAX};

        while (true) {
            int curMin = 1e9, curMax = -1e9, ind = 0;
            for (int i = 0; i < n; i++) {
                int cur = nums[i][indices[i]];
                if (cur < curMin) {
                    curMin = cur;
                    ind = i;
                }
                if (cur > curMax) {
                    curMax = cur;
                }
            }
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }
            if (++indices[ind] == nums[ind].size()) break;
        }
        return range;
    }
};