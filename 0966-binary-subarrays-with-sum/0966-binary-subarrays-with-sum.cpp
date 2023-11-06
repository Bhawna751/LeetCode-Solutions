class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int ans=0,i=0,n=nums.size();
        for(int j=0;j<n;j++){
            goal-=nums[j];
            while(goal<0){
                goal+=nums[i++];
            }
            ans+=j-i+1;
        }
        return ans;
    }
};