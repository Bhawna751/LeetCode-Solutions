class Solution {
    public int countHillValley(int[] nums) {
        int ans=0;
        int n=nums.length;
        for(int i=1,j=0;i<n-1;i++){
            if((nums[j]<nums[i] && nums[i]>nums[i+1]) || (nums[j]>nums[i] && nums[i]<nums[i+1])){    
            ans++;
            j=i;
            }
        }
        return ans;
    }
}