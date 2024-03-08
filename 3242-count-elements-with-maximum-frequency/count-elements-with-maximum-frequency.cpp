class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> st;
        for(int it:nums){
            st[it]++;
        }
        int maxi=0;
        for(auto& iter : st){
            maxi = std::max(maxi,iter.second);
        }
        int freq=0;
        for(auto &iter : st){
            if(iter.second == maxi) freq++;
        }
        int total = freq*maxi;
        return total;
    }
};