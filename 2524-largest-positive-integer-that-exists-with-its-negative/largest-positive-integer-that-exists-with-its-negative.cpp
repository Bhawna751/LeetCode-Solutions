class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high = n-1,ans=0;
        while(low<high){
            if(nums[low]+nums[high]==0){
                return nums[high];
            }
            else if(nums[low]+nums[high]<0){
                low++;
            }
            else high--;
        }
        return -1;
    }
};