class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>&per, unordered_map<int,int> &mpp, int n){
        if(per.size()==n){
            ans.push_back(per);
            return;
        }
        for(auto it:mpp){
            int num = it.first;
            int occur = it.second;
            if(occur==0)continue;
            per.push_back(num);
            mpp[num]--;
            solve(ans,per,mpp,n);
            per.pop_back();
            mpp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }
        vector<int> per;
        solve(ans,per,mpp,nums.size());
        return ans;
    }
};