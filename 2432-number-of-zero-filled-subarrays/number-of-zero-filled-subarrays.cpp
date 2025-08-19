class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans =0;
        long long zeroes = 0;
        for(int i=0;i<n;i++){
            if(nums[i]== 0) zeroes++;
            else {
                if(zeroes>0){
                    long long res = (zeroes * (zeroes+1))/2;
                    ans += res;
                }
                zeroes =0;
            }
        }
        if(zeroes > 0){
            long long res = (zeroes*(zeroes+1))/2;
            ans += res;
        }
        return ans;
    }
};