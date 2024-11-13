class Solution {
public:
    int partitions(vector<int>&nums, int target){
        int n=nums.size();
        int cnt=1;
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(sum + nums[i] <= target)sum += nums[i];
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = partitions(nums,mid);
            if(cnt>k)low=mid+1;
            else high = mid-1;
        }
        return low;
    }
};