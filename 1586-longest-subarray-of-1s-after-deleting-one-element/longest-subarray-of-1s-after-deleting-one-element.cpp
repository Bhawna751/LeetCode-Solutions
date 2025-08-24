class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int ans=0, cnt0=0;
        while(j<nums.size()){
            if(nums[j] == 1) j++;
            else{
                cnt0++;
                j++;
            }
            while(cnt0 > 1){
                if(nums[i] == 0) cnt0--;
                i++;
            }
            ans = max(ans,j-i-1);
        }
        if(cnt0 == 0) return nums.size()-1;
        else return ans;
        
    }
};