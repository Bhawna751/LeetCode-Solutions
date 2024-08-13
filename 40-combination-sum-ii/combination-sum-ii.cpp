class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        combination(ans,subset,candidates,target,0);
        return ans;
    }
    void combination(vector<vector<int>>&ans,vector<int>&subset, vector<int>&candidates, int target,int ind){
        if(target == 0){
            ans.push_back(subset);
            return;
        }
        for(int i = ind;i<candidates.size() && target>=candidates[i];i++){
            if(i==ind || candidates[i]!=candidates[i-1]){
                subset.push_back(candidates[i]);
                combination(ans,subset,candidates,target-candidates[i],i+1);
                subset.pop_back();
            }
        }
    }
};