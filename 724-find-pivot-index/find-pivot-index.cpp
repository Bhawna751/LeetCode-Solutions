class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        
        int right = accumulate(nums.begin(),nums.end(),0);
        int left =0; 
        for(int i=0;i<nums.size();i++){
            right = right - nums[i];
            if(right == left) return i;
            left += nums[i];
        }
        return -1;
    }
};