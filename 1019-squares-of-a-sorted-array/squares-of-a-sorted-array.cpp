class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int low=0, high=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[high]) > abs(nums[low])){
                ans[i] = nums[high] * nums[high];
                high--;
            }
            else{
                ans[i] = nums[low] * nums[low];
                low++;
            }
        }
        return ans;
    }
};