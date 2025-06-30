class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=1, st=0, nst=0;i<nums.size();i++){
            if(nums[i] - nums[st] > 1) st= nst;
            if(nums[i] != nums[i-1]) nst=i;
            if(nums[i] - nums[st] == 1) ans=max(ans, i-st+1);
        }
        return ans;
    }
};