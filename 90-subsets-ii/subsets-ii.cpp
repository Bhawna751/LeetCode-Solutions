class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>&subset, vector<int>&nums, int ind){
        if(ind == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        solve(ans,subset,nums,ind+1);
        subset.pop_back();
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i] != nums[ind]){
                solve(ans,subset,nums,i);
                return;
            }
        }
        solve(ans,subset,nums,nums.size());
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        solve(ans,subset,nums,0);
        return ans;
    }
};