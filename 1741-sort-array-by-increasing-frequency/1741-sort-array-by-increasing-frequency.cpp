class Solution {
public:
    static bool comparator(pair<int,int>&a, pair<int,int>&b){
        return (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size()==1) return nums;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> freq;
        for(auto it:mpp){
            freq.push_back(it);
        }
        sort(freq.begin(), freq.end(),comparator);
        vector<int> ans;
        for(auto it: freq){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};