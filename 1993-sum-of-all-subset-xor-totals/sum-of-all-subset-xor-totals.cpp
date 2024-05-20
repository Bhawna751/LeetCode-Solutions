class Solution {
public:
    void generate(vector<int>& nums,int ind,vector<int> subset,vector<vector<int>> &subsets){
        if(ind == nums.size()){
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        generate(nums,ind+1,subset,subsets);
        subset.pop_back();
        generate(nums,ind+1,subset,subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> subsets;
        generate(nums,0,{},subsets);
        int ans=0;
        for(auto &it:subsets){
           int xort = 0;
           for(int num:it){
                xort = xort^num;
           }
           ans += xort;
        }
        return ans;
    }
};