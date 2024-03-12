class Solution {
public:
    void subset(int ind,vector<int>&candidates,int target,vector<int>&ds,vector<vector<int>> &ans){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            subset(ind,candidates,target-candidates[ind],ds,ans);
            ds.pop_back();
        }
        subset(ind+1,candidates,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        subset(0,candidates,target,ds,ans);
        return ans;
    }
};