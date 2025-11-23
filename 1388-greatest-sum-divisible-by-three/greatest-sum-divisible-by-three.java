class Solution {
    public int maxSumDivThree(int[] nums) {
       
        int sum=0;//sum = 23
        for(int it:nums) sum += it;
        if(sum%3==0)return sum;
        Arrays.sort(nums);// 1,3,5,6,8
        int t=0,cnt=0;
        if(sum%3==2){
            for(int it:nums){
                if(it%3==2){
                    if(cnt==2) return sum-Math.min(it,t);
                    return sum-it;//23-5 = 18
                }
                else if(it%3==1 && cnt<2){
                    t += it;//t = 1
                    cnt++;//cnt=1
                }
            }
            return cnt==2 ? sum-t : 0;
        }else{
            for(int it:nums){
                if(it%3==1){
                    if(cnt==2)return sum-Math.min(it,t);
                    return sum-it;
                }else if(it%3==2 && cnt<2){
                    t += it;
                    cnt++;
                }
            }
            return (cnt==2) ? sum-t : 0;
        }
    }
}