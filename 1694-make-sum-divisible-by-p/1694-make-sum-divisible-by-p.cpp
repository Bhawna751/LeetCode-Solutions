class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;

        for(int it: nums){
            total = (total + it)%p;
        }

        int target = total % p;
        if(target == 0) return 0;
        if(total % p == 0)return 0;

        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int cur = 0, mini = n;

        for(int i = 0;i<n;i++){
            cur = (cur + nums[i]) % p;
            int need = (cur - target + p)%p;
            if(mpp.find(need) != mpp.end()){
                mini = min(mini, i - mpp[need]);
            }
            mpp[cur] = i;
        }
        return mini == n ? -1 : mini;
    }
};