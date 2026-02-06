class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }
        int cnt=0;
        int ans=0;
        for(auto it:mpp){
            if(it.second > cnt){
                cnt = it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};