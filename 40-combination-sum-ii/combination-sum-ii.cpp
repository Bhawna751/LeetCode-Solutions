class Solution {
public:
    void solve(vector<int>&candidates, vector<vector<int>>&ans, vector<int>&subset, int ind,int sum){
        if(sum ==0){
            ans.push_back(subset);
            return;
        }
        if(sum<0 || ind == candidates.size()) return;
        subset.push_back(candidates[ind]);
        solve(candidates,ans, subset, ind+1,sum-candidates[ind]);
        subset.pop_back();
        for(int i=ind+1;i<candidates.size();i++){
            if(candidates[i] != candidates[ind]){
                solve(candidates,ans,subset,i,sum);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>subset;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,subset,0,target);
        return ans;
    }
};