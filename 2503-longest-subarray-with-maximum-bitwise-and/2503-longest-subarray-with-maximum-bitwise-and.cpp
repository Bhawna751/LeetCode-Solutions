class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0 , streak=0, ans=0;
        for(int it:nums){
            if(it>maxVal){
                maxVal = it;
                ans = streak = 0;
            }
            if(maxVal == it) streak++;
            else streak = 0;
            ans = max(ans,streak);
        }
        return ans;
    }
};