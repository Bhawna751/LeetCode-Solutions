class Solution {
public:
    void subset(vector<vector<int>> &ans,vector<int> nums,int i){
        int j=0;
        vector<int> subsets;
        while(i>0){
            if((i&1) == 1)subsets.push_back(nums[j]);
            j++;
            i=i>>1;
        }
        ans.push_back(subsets);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
           subset(ans,nums,i);
        }
        return ans;
    }
};