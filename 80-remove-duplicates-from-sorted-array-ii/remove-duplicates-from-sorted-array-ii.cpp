class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ind =0, val=nums[ind];
        int flag =0;
        for(int i=0;i<n;i++){
            if(val==nums[i]){
                flag++;
            }
            else{
                nums[ind] = val;
                if(flag > 1){
                    ind++;
                    nums[ind]=val;
                }
                ind++;
                val = nums[i];
                flag = 1;
            }
        }
        nums[ind] = val;
        if(flag > 1){
            ind++;
            nums[ind]=val;

        }
        return ind+1;
    }
};