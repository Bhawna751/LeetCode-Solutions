class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=0;
        int n = nums.size();
        for(int it:nums){
            mpp[it]++;
        }
        int cnt = mpp[0];
        for(auto it:mpp){
            if(it.second > cnt){
                cnt = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};