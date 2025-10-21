class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(), nums.end()) + k + 2;
        int *cnt = new int[maxi]();
        for(int it:nums) cnt[it]++;
        for(int i=1;i<maxi;i++){
            cnt[i] += cnt[i-1];
        }
        int ans=0;
        for(int i=0;i<maxi;i++){
            int l = max(0,i-k);
            int r = min(maxi-1,i+k);
            int total = cnt[r] - (l ? cnt[l-1] : 0);
            int freq= cnt[i] - (i ? cnt[i-1]:0);
            ans=max(ans,freq+min(numOperations, total-freq));
        }
        return ans;
    }
};