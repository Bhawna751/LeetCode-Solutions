class Solution {
    public boolean sorted(List<Integer> nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums.get(i)>nums.get(i+1))return false;
        }
        return true;
    }
    
    public void merge(List<Integer> nums){
        
        int ind=0;
        int minsum=Integer.MAX_VALUE;
        for(int i=0;i<nums.size()-1;i++){
            int sum= nums.get(i)+nums.get(i+1);
            if(sum<minsum){   
                ind=i;
                minsum=sum;
            }
        }
        nums.set(ind,minsum);
        nums.remove(ind+1);
    }
    public int minimumPairRemoval(int[] nums) {
        
        List<Integer> list = new ArrayList<>();
        for(int it:nums)list.add(it);
        int op=0;
        while(!sorted(list)){
            merge(list);
            op++;
        }
        return op;
    }
}