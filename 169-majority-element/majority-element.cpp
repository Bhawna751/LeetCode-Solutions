class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int it:nums)mpp[it]++;
        for(auto it: mpp){
            if(it.second > n/2)return it.first;
        }
        return -1;
    }
};