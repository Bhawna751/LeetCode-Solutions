class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                i=j;
                break;
            }
        }
        if(i==-1)return;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);i++;
            }
        }
    }
};