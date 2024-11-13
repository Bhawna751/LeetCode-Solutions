class Solution {
public:
    int lower_bound(vector<int>& nums, int low, int high, int ele){
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid] >= ele) high = mid-1;
            else low = mid+1;
            
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int low = lower_bound(nums,i+1,nums.size()-1, lower - nums[i]);
            int high = lower_bound(nums,i+1, nums.size()-1, upper-nums[i]+1);
            ans += (high-low)*1LL;
        }
        return ans;
    }
};