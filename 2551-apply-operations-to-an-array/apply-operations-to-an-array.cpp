class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1] && nums[i] != 0){
                nums[i] = nums[i]*2;
                nums[i+1]  = 0;
            }
        }
        for( int it:nums){
            if(it != 0) ans.push_back(it);
        }
        while(ans.size() < n) ans.push_back(0);
        return ans;
    }
};