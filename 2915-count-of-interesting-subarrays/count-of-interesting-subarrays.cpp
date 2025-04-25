class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        long long ans=0;
        int pre = 0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            pre += nums[i] % modulo == k;
            ans += mpp[(pre-k+modulo)%modulo];
            mpp[pre%modulo]++;
        }
        return ans;
    }
};