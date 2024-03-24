class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left=0,right=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[right]) > abs(nums[left])){
                ans[i] = nums[right] * nums[right];
                right--;
            }
            else{
                ans[i]=nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};