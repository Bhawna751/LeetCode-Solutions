class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1,right = 0;
        for (auto it : nums) {
            right = max(right, it);
        }
        while (left < right) {
            int mid = (left + right) / 2;
            if (helper(mid, nums, maxOperations)) {
                right = mid;  
            } else {
                left = mid + 1;  
            }
        }
        return left;
    }
    bool helper(int maxi, vector<int>& nums, int maxOperations) {
        int total = 0;
        for (int it : nums) {
            int op = ceil(it / (double)maxi) - 1;
            total += op;
            if (total > maxOperations) return false;
        }
        return true;
    }
};