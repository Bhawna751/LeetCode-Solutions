class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cur = 0, l = 0, n = 0;
        for(int i=0;i<nums.size();i++){
            while((cur & nums[i])!= 0){
                cur = cur^nums[l];
                l++;
            }
            cur = cur | nums[i];
            n = max(n,i-l+1);
        }
        return n;
    }
};