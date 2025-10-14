class Solution {
public://1 1 1 1 1 1 1 1 2 2  k=3
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int firstLen = 0;
        int secondLen=1;
        int len=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                secondLen++;//5
            }else{
                firstLen = secondLen;//firstlen = 0
                secondLen = 1;//secondlen = 
            }
            len = max(len,max(secondLen/2, min(secondLen, firstLen)));//max(0, max(2,min(2,0))) len = 2
        }
        if(len>=k)return true;
        else return false;
    }
};