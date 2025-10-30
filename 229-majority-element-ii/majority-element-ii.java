class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int cnt1=0, cnt2=0, ele1=Integer.MIN_VALUE, ele2=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1++;//cnt1=0
                ele1=nums[i];//ele1=5
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2++;//cnt2=1
                ele2=nums[i];//ele2=2
            }
            else if(nums[i]==ele1)cnt1++;
            else if(nums[i]==ele2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        List<Integer> arr= new ArrayList<>();
        cnt1=0; cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)cnt1++;
            if(nums[i]==ele2)cnt2++;
        }
        if(cnt1>=n/3+1)arr.add(ele1);
        if(cnt2>=n/3+1)arr.add(ele2);
        return arr;
    }
}