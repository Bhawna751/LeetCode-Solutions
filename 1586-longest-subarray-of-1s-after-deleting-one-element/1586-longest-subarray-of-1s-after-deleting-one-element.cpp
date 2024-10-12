class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0;
        int window=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) cnt++;
            while(cnt > 1){
                if(nums[l] == 0) cnt--;
                l++;
            }
            window = max(window,i-l);
        }
        return window;
    }
};