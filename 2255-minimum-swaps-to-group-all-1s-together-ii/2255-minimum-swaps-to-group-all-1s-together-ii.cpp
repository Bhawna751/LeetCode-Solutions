class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int zero = miniSwap(nums,0);
        int one = miniSwap(nums,1);
        return min(zero,one);
    }
    int miniSwap(vector<int> &nums, int val){
        int n = nums.size();
        vector<int> right(n+1,0);
        for(int i=n-1;i>=0;i--){
            right[i] = right[i+1];
            if(nums[i] == (val^1)) right[i]++;
        }
        int total = right[0];
        int cur = 0;
        int mini = total - right[n-total];
        for(int i=0;i<total;i++){
            if(nums[i] == (val^1))cur++;
            int rem = total - i-1;
            int req = ((i+1) - cur) + (rem - right[n-rem]);
            mini = min(mini,req);
        }
        return mini;
    }
};