class Solution {
public:
    int ub(vector<int>&arr,int val){
        int l=0,r=arr.size()-1,ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]<=val){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int upper = ub(nums,nums[i]+2*k);
            ans=max(ans,upper-i+1);
        }
        return ans;
    }
};