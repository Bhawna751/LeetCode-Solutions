class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0, total = 0;
        for(int i=0,j=0;j<n;j++){
            total += nums[j];
            while(i<=j && total * (j-i+1) >= k){
                total -= nums[i];
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
};