class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), blocks = (n + 200 - 1) / 200;
        int ans = 0;

        vector<int> block(blocks, 0);
        vector<int> accum(n, 0);
        vector<vector<int>> blockL(blocks, vector<int>(n * 2 + 1, (int)1e9));
        unordered_map<int, int> last;

        for (int r = 0; r < n; r++) {
            int l = last.count(nums[r]) ? last[nums[r]] + 1 : 0;
            int delta = nums[r] % 2 ? -1 : +1;
            int lblk = l / 200, rblk = r / 200;

            for (int blk = lblk; blk <= rblk; blk++) {
                if (blk == lblk || blk == rblk) {
                    for (int i = min(blk * 200 + 200 - 1, n - 1); i >= blk * 200; i--)
                        blockL[blk][accum[i] + n] = 1e9;
                    
                    for (int i = min(blk * 200 + 200 - 1, n - 1); i >= blk * 200; i--) {
                        accum[i] += (i >= l && i <= r) ? delta : 0;
                        blockL[blk][accum[i] + n] = i;
                    }
                }
                else 
                    block[blk] += delta;
            }
            for (int blk = 0; blk <= rblk; blk++)
                ans = max(ans, r - blockL[blk][-block[blk] + n] + 1);

            last[nums[r]] = r;
        }
        return ans;
    }
};