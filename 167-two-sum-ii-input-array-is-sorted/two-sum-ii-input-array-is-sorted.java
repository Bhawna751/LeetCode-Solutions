class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int l=0,h=n-1;
        int[] ans=new int[2];
        while(l<h){
            if(numbers[l] + numbers[h] == target){
                ans[0]=l+1;
                ans[1]=h+1;
                return ans;
            }
            else if(numbers[l] + numbers[h] < target){
                l++;
            }
            else h--;
        }
        return ans;
    }
}