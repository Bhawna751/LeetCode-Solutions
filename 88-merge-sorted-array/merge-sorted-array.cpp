class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1;
        int ind = m+n-1;
        while(j>=0){
            if(i>=0 && nums1[i]>=nums2[j]){
                nums1[ind]=nums1[i];
                i--;
                ind--;
            }
            else {
                nums1[ind]=nums2[j];
                j--;
                ind--;
            }
        }
    }
};