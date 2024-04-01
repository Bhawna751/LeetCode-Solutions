typedef long long ll;
class Solution {
public:
    ll countAlternatingSubarrays(vector<int>& nums) {
        int start=0;
        ll ans=0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                ll len=i-start;
                ans += (ll)(len*(len+1)*1ll)/2;
                start=i;
            }
        }
        ll len=nums.size()-start;
        ans += (ll)(len*(len+1)*1ll)/2;
        return ans;
    }
    
};