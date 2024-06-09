class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        
        int total = accumulate(nums.begin(),nums.end(),0);
        int prefix = 0;
        int suffix = total; 
        for(int i=0;i<nums.size();i++){
            if(i != 0) prefix += nums[i-1];
            suffix = total - prefix - nums[i];
            if(suffix == prefix) return i;
        }
        return -1;
    }
};