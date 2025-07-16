class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int parity=nums[0]%2, odd=0, even=0;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)even++;
            else odd++;
            if(nums[i]%2 == parity){
                flag++;
                parity = 1-parity;
            }
        }
        return max(flag, max(odd, even));
    }
};