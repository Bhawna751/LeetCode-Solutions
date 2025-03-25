class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1e9, n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxi = max(maxi,sum);
            if(sum < 0) sum=0;
        }
        return maxi;
    }
};