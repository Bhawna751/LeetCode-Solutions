class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long mod = 1e9+7;
        unordered_map<int,long long> right,left;
        for(int it:nums){
            right[it]++;
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            right[nums[i]]--;
            long long req = (long long)nums[i]*2;
            long long cntl = left.count(req) ? left[req] : 0;
            long long cntr = right.count(req) ? right[req] : 0;
            ans = (ans+(left[req] * right[req])%mod)%mod;
            left[nums[i]]++;
        }
        return (int)(ans%mod);
    }
};