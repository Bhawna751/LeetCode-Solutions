class Solution {
    public int minimumOperations(int[] nums) {
        int ans=0;
        for(int it:nums){
            if(it % 3 == 1 || it%3==2)ans++;
        }
        return ans;
    }
}