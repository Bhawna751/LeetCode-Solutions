class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {};
        vector<int>ans;
        unordered_map<int,int> mpp;
        for(int it:nums)mpp[it]++;
        for(auto iter:mpp){
            if(iter.second==2)ans.push_back(iter.first);
        }
        return ans;
    }
};