class Solution {
public:
    void permut(int ind,vector<vector<int>> &ans,vector<int>& nums){
        if(ind==nums.size()){
            vector<int> ds;
            for(int i=0;i<nums.size();i++){
                ds.push_back(nums[i]);
            }
            ans.push_back(ds);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            permut(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        permut(0,ans,nums);
        return ans;
    }
};