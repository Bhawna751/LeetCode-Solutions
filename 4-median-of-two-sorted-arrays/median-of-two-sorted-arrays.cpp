class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m)return findMedianSortedArrays(nums2,nums1);
        int ind = n+m;
        int left = (ind+1)/2;
        int low = 0, high = n;
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : -1e9;
            int r1 = (mid1 < n) ? nums1[mid1] : 1e9;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : -1e9;
            int r2 = (mid2 < m) ? nums2[mid2] : 1e9;

            if (l1 <= r2 && l2 <= r1) {
                if (ind % 2 == 1) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            } 
            else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};