class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();//0 1 0  k=1 
        deque<int> dq;//dq --> 1
        int flipState = 0, ans = 0;//1
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipState = flipState ^ dq.front();
                dq.pop_front();
            }
            if (flipState == nums[i]) {
                if (i + k > n) return -1;
                dq.push_back(1);
                flipState = flipState ^ 1;
                ans++;
            }
            else dq.push_back(0);
        }
        return ans;//ans = 1
    }
};