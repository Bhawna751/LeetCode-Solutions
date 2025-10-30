class Solution {
    public int findDuplicate(int[] nums) {
        int n= nums.length;
        int[] freq = new int[n+1];
        for(int it:nums){
            if(freq[it]==0){
                freq[it]++;
            }
            else return it;
        }
        return 0;
    }
}