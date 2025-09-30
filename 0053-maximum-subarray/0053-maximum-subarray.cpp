class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi = -1e9;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0)sum =0;
        }
        return maxi;
    }
};