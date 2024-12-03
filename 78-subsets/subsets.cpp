class Solution {
public:
    void solve(int ind,int n,vector<int>& nums,vector<int>&arr,vector<vector<int>> &ans){
        if(ind==n){
            ans.push_back(arr);
            return;
        }
        solve(ind+1,n,nums,arr,ans);
        arr.push_back(nums[ind]);
        solve(ind+1,n,nums,arr,ans);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>arr;
        solve(0,nums.size(),nums,arr,ans);
        return ans;
    }
};