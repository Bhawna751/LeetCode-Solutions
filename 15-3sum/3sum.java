class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Set<List<Integer>> st=new HashSet<>();
        for(int i=0;i<n;i++){
            Set<Integer> hashset = new HashSet<>();
            for(int j=i+1;j<n;j++){
                int third = 0 - (nums[i] + nums[j]);
                if(hashset.contains(third)){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(third);
                    Collections.sort(temp);
                    st.add(temp);
                }
                hashset.add(nums[j]);
            }
        }
        List<List<Integer>> ans = new ArrayList<>(st);
        return ans; 
    }
}