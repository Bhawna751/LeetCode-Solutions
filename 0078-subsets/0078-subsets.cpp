class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&subset,vector<int>&nums, int ind,int n){
        if(ind==n){
            ans.push_back(subset);
            return;
        }

        solve(ans, subset,nums,ind+1,n);
        subset.push_back(nums[ind]);
        solve(ans,subset,nums,ind+1,n);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int>subset;
        solve(ans,subset,nums,0,n);
        return ans;
    }
};