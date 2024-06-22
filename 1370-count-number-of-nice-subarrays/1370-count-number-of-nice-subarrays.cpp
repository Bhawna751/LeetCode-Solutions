class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, n=nums.size();//1 1 2 1 1    n = 5
        int odd = 0,cnt=0;
        int low = 0,high=0;
        while(high < n){// 4 < 5
            if(nums[high]%2 != 0){
                cnt=0;//cnt = 0
                odd++;//odd = 3
            }
            while(odd == k){
                cnt++;//cnt = 2
                odd -= nums[low]&1;//odd = 3 - 
                low++;//low = 1
            }
            ans += cnt;//ans = 1
            high++;//high = 4
        }
        return ans;
    }
};