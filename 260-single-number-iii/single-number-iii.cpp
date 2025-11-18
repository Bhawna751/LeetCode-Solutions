class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1=0, xor2=0;
        long xorr=0;
        for(int it:nums){
            xorr = xorr^it;
        } 
        int right = (int)(xorr & (xorr-1)) ^ (int)xorr;
        for(int i=0;i<n;i++){
            if((nums[i] & right)!=0)xor1 = xor1^nums[i];
            else xor2 = xor2 ^nums[i];
        }
        if(xor1 < xor2) return {xor1,xor2};
        else return {xor2,xor1};
    }
};