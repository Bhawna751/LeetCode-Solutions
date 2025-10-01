class Solution {
public:
    long long helper(vector<int>&nums2, long long threshold, long long cur){
        int m = nums2.size();
        int l=0, r=m-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(threshold >= 0 && nums2[mid] * threshold <= cur
                || threshold <0 && nums2[mid] * threshold > cur) l = mid+1;
                else r = mid-1;
        }
        if(threshold >= 0) return l;
        else return m-l;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        long long ans=-1e10, high = 1e10;
        while(ans<=high){
            long long mid = (ans+high)/2;
            long long cnt = 0;
            for(int i=0;i<n;i++){
                cnt += helper(nums2,nums1[i],mid);
            }
            if(cnt < k) ans = mid+1;
            else high = mid-1;
        }
        return ans;
    }
};