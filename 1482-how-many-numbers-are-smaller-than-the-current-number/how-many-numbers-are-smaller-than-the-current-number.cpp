class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<copy.size();i++){
            if(mpp.find(copy[i]) == mpp.end()){
                mpp[copy[i]]=i;
            }
        }
        vector<int>ans;
        for(int it:nums) ans.push_back(mpp[it]);
        return ans;
    }
};