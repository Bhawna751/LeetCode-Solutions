class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0, cnt=0;
        int l=0,h=0;
        int odd=0;
        while(h<n){
            if(nums[h]%2!=0){
                cnt=0;
                odd++;
            }
            while(odd==k){
                cnt++;
                odd -= (nums[l] % 2);
                l++;
            }
            ans += cnt;
            h++;//3
        }
        return ans;
    }
};