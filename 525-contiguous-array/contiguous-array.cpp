class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> ans(2*nums.size()+1,-1e9);
        ans[nums.size()]=-1;
        int len=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] == 0 ? -1:1);
            if(ans[sum + nums.size()] >= -1) len = max(len,i-ans[sum+nums.size()]);
            else ans[sum+nums.size()]=i;
        }
        return len;
    }
};