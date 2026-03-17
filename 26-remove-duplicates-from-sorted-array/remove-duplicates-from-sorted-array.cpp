class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int unique=0;
        for(int i=1;i<n;i++){
            if(nums[unique]!=nums[i]){
                nums[unique+1]= nums[i];
                unique++;
            }
        }
        return unique+1;
    }
};