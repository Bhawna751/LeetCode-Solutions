class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m-1, r=0;
        while(l>=0 && r<n){
            if(nums1[l] > nums2[r]){
                swap(nums1[l], nums2[r]);
                    l--;r++;
                
            }else break;
        }
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());
        for(int i=m;i<m+n;i++) nums1[i] = nums2[i-m];
    }
};