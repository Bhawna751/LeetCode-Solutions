class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9,sum=0;
        for(int i = 0;i<n;i++){
             sum += nums[i];
             maxi = max(maxi, sum) ;  
             if(sum<0)sum=0;
            
        }
        return maxi;
    }
};