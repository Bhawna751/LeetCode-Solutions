class Solution {
public:
    int singleNumber(vector<int>& nums) { //[0,1,0,1,0,1,99]
        sort(nums.begin(),nums.end());//0 0 0 1 1 1 99
        int n=nums.size();//7
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        for(int i = 1;i<n-1;i++){
            if(nums[i] != nums[i+1] && nums[i]!= nums[i-1]) return nums[i];
        }
        return -1;
    }
};