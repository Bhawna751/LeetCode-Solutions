class Solution {
public:
    int lowerBound(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ind = nums.size();

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] < 0) {
                l = mid + 1;
            } else if (nums[mid] >= 0) {
                r = mid - 1;
                ind = mid;
            }
        }

        return ind;
    }
    int upperBound(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int ind = nums.size();

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] <= 0) {
                l = mid + 1;
            } else if (nums[mid] > 0) {
                r = mid - 1;
                ind = mid;
            }
        }

        return ind;
    }
    int maximumCount(vector<int>& nums) {
        int pos= nums.size() - upperBound(nums);
        int neg= lowerBound(nums);
        return max(pos,neg);
    }
};