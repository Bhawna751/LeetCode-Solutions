class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int>freq;
        map<int,int>sweep;
        for(auto &it:nums){
            freq[it]++;
            sweep[max(0,it-k)]++;
            sweep[it+k+1]--;
            if(sweep.find(it) == sweep.end()) sweep[it]=0;
        }
        int ans=0, cnt=0;
        for(auto &it:sweep){
            cnt+=it.second;
            ans=max(ans,freq[it.first]  + min(numOperations,(cnt-freq[it.first])));
        }
        return ans;
    }
};