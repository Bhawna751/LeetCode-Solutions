class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(count>1){
                return false;
            }
            else if(nums[i]>nums[i+1]){
                count++;}
        }
        if(nums[nums.size()-1]>nums[0])
            count++;
        
        if(count>1)
            return false;
        else 
            return true;
    }
};