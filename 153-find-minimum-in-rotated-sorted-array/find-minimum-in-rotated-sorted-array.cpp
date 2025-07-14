class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=1e9, low=0, n=nums.size(), high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else if(nums[mid] <= nums[high]){
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};