class Solution {
public:
    void solve(vector<int>&candidates,int ind,int target, vector<vector<int>>&ans, vector<int>&subset ){
        if(target<0 || ind<0)return;
        if(target == 0){
            ans.push_back(subset);
            return;
        }
        solve(candidates,ind-1,target,ans,subset);
        subset.push_back(candidates[ind]);
        solve(candidates,ind,target-candidates[ind],ans,subset);
        subset.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(candidates,candidates.size()-1,target,ans,subset);
        return ans;
    }
};