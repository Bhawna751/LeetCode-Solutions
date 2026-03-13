class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int presum=0, ans=0;
        map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            presum += nums[i];
            int req = presum-k;
            ans += mpp[req];
            mpp[presum]++;
        }
        return ans;
    }
};