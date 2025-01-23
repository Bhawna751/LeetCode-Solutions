class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset,int ind){
        if(nums.size()==ind){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        solve(nums,ans,subset,ind+1);
        subset.pop_back();
        for(int j=ind+1;j<nums.size();j++){
            if(nums[j]!=nums[ind]){
                solve(nums,ans,subset,j);
                return;
            }
        }
        solve(nums,ans,subset,nums.size());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        solve(nums,ans,subset,0);
        return ans;
    }
};