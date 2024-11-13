class Solution {
public:
    int lower_bound(vector<int>& nums, int low, int high, int ele){
        while(low<=high){
            int mid = (high+low)/2;//mid=
            if(nums[mid] >= ele) high = mid-1;//high  = 1
            else low = mid+1;//low = 2
            
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());//0,1,4,4,5,7 lower  = 3 upper = 6
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int low = lower_bound(nums,i+1,nums.size()-1, lower - nums[i]);//low=2, low=2, high=5, ele = 2
            int high = lower_bound(nums,i+1, nums.size()-1, upper-nums[i]+1);//high=5, low=1, high=5, ele = 7
            ans += (high-low)*1LL;//ans = 3
        }
        return ans;
    }
};