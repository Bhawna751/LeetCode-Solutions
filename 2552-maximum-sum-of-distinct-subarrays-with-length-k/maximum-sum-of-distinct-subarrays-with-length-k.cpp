class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0;
        int l=0,r=0;
        unordered_map<int,int> mpp;
        while(r<nums.size()){
            int num = nums[r];
            int last = (mpp.count(num) ? mpp[num] : -1);
            while(l<=last || r-l+1 > k){
                sum-=nums[l];
                l++;
            }
            mpp[num]=r;
            sum+=nums[r];
            if(r-l+1==k)ans=max(ans,sum);
            r++;
        }
        return ans;
    }
};