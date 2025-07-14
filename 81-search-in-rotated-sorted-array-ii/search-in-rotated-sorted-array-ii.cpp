class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target)return true;
            if(nums[low] == nums[mid] && nums[high] == nums[mid]){
                low++;
                high--;
                continue;
            }
            if(nums[mid]>=nums[low]){
                if(nums[mid] >= target && nums[low] <= target) high=mid-1;
                else low= mid+1;
            }
            else if(nums[mid]<=nums[high]){
                if(nums[mid] <= target && nums[high] >= target) low=mid+1;
                else high= mid-1;
            }
        }
        return false;
    }
};