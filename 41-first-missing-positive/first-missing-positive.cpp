class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cur = nums[i];
            if(cur == i+1 || cur<=0 || cur>n)continue;
            swap(nums[i],nums[cur-1]);
            if(nums[i] != nums[cur-1]) i--;
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};