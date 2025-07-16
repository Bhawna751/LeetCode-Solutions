class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = (n1 + n2);
        int ind1 = n / 2 - 1;
        int ind2 = n / 2;
        int cnt = 0;
        int ind1Ele = -1, ind2Ele = -1;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (ind1 == cnt)
                    ind1Ele = nums1[i];
                if (ind2 == cnt)
                    ind2Ele = nums1[i];
                cnt++;
                i++;
            } else {
                if (ind1 == cnt)
                    ind1Ele = nums2[j];
                if (ind2 == cnt)
                    ind2Ele = nums2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1) {
            if (ind1 == cnt)
                ind1Ele = nums1[i];
            if (ind2 == cnt)
                ind2Ele = nums1[i];
            cnt++;
            i++;
        }
        while(j<n2){
            if(ind1 == cnt) ind1Ele = nums2[j];
            if(ind2 == cnt) ind2Ele = nums2[j];
            cnt++;
            j++;
        }
        if(n%2==1) return (double)ind2Ele;
        return (double)((double)(ind1Ele + ind2Ele))/2.0;
    }
};