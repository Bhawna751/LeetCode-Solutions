class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int it:nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second > 1) return it.first;
        }
        return -1;
    }
};