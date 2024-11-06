class Solution {
public:
    bool merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right-left+1);
        int low = left, high = mid + 1, ind = 0;
        while (low <= mid && high <= right) {
            if (nums[low] <= nums[high]) {
                temp[ind++] = nums[low++];
            } 
            else {
                int l = 0, r = 0;
                for (int i = 0; i <= 9; i++) {
                    int mask = 1 << i;
                    if ((nums[high] & mask) != 0) r++;
                }
                
                for (int i = low; i <= mid; i++) {
                    l = 0;
                    for (int j = 0; j<=9 ; j++) {
                        int mask = 1 << j;
                        if ((nums[i] & mask) != 0)
                            l++;
                    }
                    if (l != r)
                        return false;
                }
                temp[ind++] = nums[high++];
            }
        }
        while (low <= mid) {
            temp[ind++] = nums[low++];
        }
        while (high <= right) {
            temp[ind++] = nums[high++];
        }
        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }

        return true;
    }

    bool mergeSort(vector<int>& nums, int left, int right) {
        int mid = (left+right) / 2;//mid = 2
        if (left == right) return true;
        bool flag = true;
        flag &= mergeSort(nums, left, mid);
        flag &= mergeSort(nums, mid + 1, right);
        flag &= merge(nums, left, mid, right);
        return flag;
    }

    bool canSortArray(vector<int>& nums) {
        bool flag = true;// [8,4,2,30,15]
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};