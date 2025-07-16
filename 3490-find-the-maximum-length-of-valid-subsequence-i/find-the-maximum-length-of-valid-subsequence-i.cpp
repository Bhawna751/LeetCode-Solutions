class Solution {
public:
    int maximumLength(vector<int>& nums) {//[1,2,1,1,2,1,2]
        int parity=nums[0]%2, odd=0, even=0;//parity = 1
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)even++;//even=3
            else odd++;//odd=4
            if(nums[i]%2 == parity){
                flag++;//flag = 6
                parity = 1-parity;//parity = 1
            }
        }
        return max(flag, max(odd, even));// max(6, (3,4)) => 6
    }
};