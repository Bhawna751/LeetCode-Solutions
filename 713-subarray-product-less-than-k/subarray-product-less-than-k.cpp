class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)return 0;
        int first=0,prod=1,cnt=0;
        for(int i=0;i<n;i++){
            prod = prod*nums[i];
            while(prod>=k && first<n){
                prod = prod/nums[first];
                first++;
            }
            if(prod<k) cnt+= i-first+1;
        }
        return cnt;
    }
};