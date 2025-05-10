class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0, s2=0;
        long long zero1=0, zero2=0;
        for(int it:nums1){
            s1 += it;
            if(it == 0){
                s1++;
                zero1++;
            }
        }
        for(int it:nums2){
            s2+=it;
            if(it==0){
                s2++;
                zero2++;
            }
        }
        if(!zero1 && s2 > s1 || !zero2 && s1 > s2) return -1;
        return max(s1,s2);
        
    }
};