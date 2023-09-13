class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
       int xor1 = 0;
       for (int i = 0;i<N;i++){
           xor1 ^= nums[i]^i;
       } 
       xor1 ^= N;
       return xor1;
    }
};