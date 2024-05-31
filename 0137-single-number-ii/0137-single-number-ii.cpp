class Solution {
public:
    int singleNumber(vector<int>& nums) {//[0,1,0,1,0,1,99] 
        int n=nums.size();
        for(int i=0;i<n;i++){
            bool found=false;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j] && i!=j) found = true;
            }
            if(!found) return nums[i];
        }
        return -1;
    }
};